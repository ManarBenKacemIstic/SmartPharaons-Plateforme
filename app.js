const express = require('express');
const { InfluxDB } = require('@influxdata/influxdb-client');
const cors = require('cors');
const path = require('path');

const influxConfigChallenges = {
  token: 'SDdDNI2JkgG8LW88xBVZEJZoGlYZICg92KhgVrnaOQ_Y9zSdKydq8bMToNDa4qBAz7E3zUz5eXOhahhd-xNL1Q==',
  org: 'makerlabs',
  bucket: 'ISTICROBOTS',
  url: 'http://192.168.1.16:8086',
};

const clientChallenges = new InfluxDB({ url: influxConfigChallenges.url, token: influxConfigChallenges.token });
const app = express();
const PORT = 3000;

app.use(cors());
app.use(express.static(path.join(__dirname)));

async function fetchChallenges() {
  try {
    const queryApi = clientChallenges.getQueryApi(influxConfigChallenges.org);
    const query = `
      from(bucket: "${influxConfigChallenges.bucket}")
        |> range(start: -1h)
        |> filter(fn: (r) => r._measurement == "wokwi")
        |> last()
    `;

    const challenges = {};
    const tables = await queryApi.collectRows(query);

    tables.forEach((row) => {
      if (row._field.startsWith("challenge") || row._field.startsWith("deb") || row._field === "fin" || row._field === "temps_passe" || row._field === "nom_club" || row._field === "nom_robot" || row._field === "score" || row._field === "dis") {
        challenges[row._field] = row._value;
      }
    });

    return challenges;
  } catch (err) {
    console.error('Error querying InfluxDB:', err);
    throw new Error('Failed to fetch challenges data');
  }
}

app.get('/robot_challenges', async (req, res) => {
  try {
    const data = await fetchChallenges();
    res.json(data);
  } catch (err) {
    console.error('Error in /robot_challenges endpoint:', err);
    res.status(500).json({ message: 'Error fetching data from InfluxDB', error: err.message });
  }
});

app.use((err, req, res, next) => {
  console.error('Global error handler:', err);
  res.status(500).json({ message: 'Internal Server Error', error: err.message });
});

app.listen(PORT, () => {
  console.log("Server is running on http://localhost:${PORT}");
});