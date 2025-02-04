#include <WiFi.h>
#include <InfluxDbClient.h>
#include <InfluxDbCloud.h>

// InfluxDB Measurement Object
Point sensor("wokwi");

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""

// InfluxDB Server Configuration
#define INFLUXDB_URL "http://192.168.1.100:8086"
#define INFLUXDB_TOKEN "O_0BF4uL0h_4eW7BpKyPrWcVn-XBy6pVQn9Zk0UEFSWFdepnFEhLr1Ewy3VFtjnSd3AEqoFR_wBiry7ODhWQSA=="
#define INFLUXDB_ORG "istic"
#define INFLUXDB_BUCKET "ISTICROBOTS"

// InfluxDB Client
InfluxDBClient client(INFLUXDB_URL, INFLUXDB_ORG, INFLUXDB_BUCKET, INFLUXDB_TOKEN);
// Pin Definitions
#define a0 987  // 30 points
#define a1 5    // 20 points
#define a2 17   // 10 points
#define a3 16   // DISQ
#define a4 15   // SUIVANT
#define a5 34   // DEP
#define a6 35   // HADH
#define a7 32   // ANUB
#define a8 33   // KBAR
#define a9 34   // CHAMS
#define a10 35  // SPIDER
#define a11 32  // FIN

// Sensor Pin Definitions
#define MAX digitalRead(a0)  // 4 BUTTONS
#define MED digitalRead(a1)
#define MIN digitalRead(a2)
#define PUSHD digitalRead(a3)
#define PUSHP digitalRead(a4)
#define DEP digitalRead(a5)
#define HADH digitalRead(a6)
#define ANUB digitalRead(a7)
#define KBAR digitalRead(a8)
#define CHAMS digitalRead(a9)
#define SPIDER digitalRead(a10)
#define FIN digitalRead(a11)

// Variables
int deb = 0;
int hadh = 0;
int anub = 0;
int kbar = 0;
int chams = 0;
int spider = 0;
int fin = 0;
int total = 0;
int disq = 0;
int id = -1;
long t3 = 0;
int y = -1;
int n1 = 0;
long wakt = 0;


void setup() {
  Serial.begin(115200);
  // Wi-Fi Connection
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");

  // InfluxDB Connection Check
  if (client.validateConnection()) {
    Serial.print("Connected to InfluxDB: ");
    Serial.println(client.getServerUrl());
  } else {
    Serial.print("InfluxDB connection failed: ");
    Serial.println(client.getLastErrorMessage());
    while (true)
      ;
  }

  // Pin Initialization
  //pinMode(BUZZER, OUTPUT);
  pinMode(a0, INPUT);
  pinMode(a1, INPUT);
  pinMode(a2, INPUT);
  pinMode(a3, INPUT);
  pinMode(a4, INPUT);


  pinMode(a5, INPUT);
  pinMode(a6, INPUT);
  pinMode(a7, INPUT);
  pinMode(a8, INPUT);
  pinMode(a9, INPUT);
  pinMode(a10, INPUT);
  pinMode(a11, INPUT);
}



void loop() {
  while (n1 == 0) {
    Serial.println("haya khouya");
    if (PUSHP == 1) {
      n1 = 1;
      id++;
      abaath_id();
    }
  }
  Serial.println("aaaaaaaaaaa nestana fl robot ymes capteur ");
  if (PUSHD == 1) {
    disq = 1;
    abaath();
    Serial.println("YRAWAH HAHAHAHAHA  ");
  }
  if (DEP == 0 && disq == 0 && y == -1) {
    t3 = millis();
    //delay(1000);
    y = 0;
    deb = 1;
    if (PUSHD == 1) {  // disqal
      disq = 1;
      y = 0;
      abaath();
      Serial.println("YRAWAH HAHAHAHAHA  ");
    }
  }

  if (HADH == 0 && disq == 0 && y == 0) {
    Serial.println("10🙂 ou disq");

    while (y == 0) {
      // bech you93ed we7ed mayet3ada ely manenzel ena
      if (MIN == 1)  // chemin 1
      {
        total = total + 10;
        y = 1;  // ENA FANA CHALLENGE
        hadh = 10;
        abaath();
        Serial.print("rak lamyt ");
        Serial.println(total);
      }

      if (PUSHD == 1) {  // disqal
        disq = 1;
        y = 1;
        abaath();
        Serial.println("YRAWAH HAHAHAHAHA  ");
      }
    }
  }




  // annubis
  if (y == 1 && ANUB == 0 && disq == 0) {

    Serial.println("20 🙂 ou ;10");
    while (y == 1) {  // bech you93ed we7ed mayet3ada ely manenzel ena

      if (MED == 1)  // chemin 1 anub
      {
        total = total + 20;
        y = 2;  // ENA FANA CHALLENGE
        anub = 20;
        abaath();
        Serial.print("rak lamyt ");
        Serial.println(total);
      }
      if (MIN == 1) {  // chemin 2 anub
        total = total + 10;
        y = 2;
        anub = 10;
        abaath();
        Serial.print("rak lamyt ");
        Serial.println(total);
      }
      if (PUSHD == 1) {  // disqal
        disq = 1;
        y = 2;
        abaath();
        Serial.println("YRAWAH HAHAHAHAHA  ");
      }
    }
  }
  // kbar

  if (y == 2 && KBAR == 0 && disq == 0) {
    Serial.println("30 🙂 ou ; 20 ");

    while (y == 2) {  // bech you93ed we7ed mayet3ada ely manenzel ena

      if (MAX == 1)  // chemin 1 kbar
      {
        total = total + 30;
        y = 3;  // ENA FANA CHALLENGE
        kbar = 30;
        abaath();
        Serial.print("rak lamyt ");
        Serial.println(total);
      }
      if (MED == 1) {  // chemin 2 kbar
        total = total + 20;
        y = 3;
        kbar = 20;
        abaath();
        Serial.print("rak lamyt ");
        Serial.println(total);
      }
      if (PUSHD == 1) {  // disqal
        disq = 1;
        y = 3;
        abaath();
        Serial.println("YRAWAH HAHAHAHAHA  ");
      }
    }
  }
  // chams
  if (y == 3 && CHAMS == 0 && disq == 0) {
    Serial.println("30 🙂 ou ; 20 ou ;10");

    while (y == 3) {  // Serial.println(PUSHD);
      if (MAX == 1) {
        total = total + 30;
        y = 4;
        chams = 30;
        abaath();
        Serial.print("rak lamyt ");
        Serial.println(total);
      }

      if (MED == 1) {
        total = total + 20;
        y = 4;
        chams = 30;
        abaath();
        Serial.print("rak lamyt ");
        Serial.println(total);
      }
      if (MIN == 1) {
        total = total + 10;
        y = 4;
        chams = 10;

        abaath();
        Serial.print("rak lamyt ");
        Serial.println(total);
      }

      if (PUSHD == 1) {
        disq = 1;
        y = 4;
        abaath();
        Serial.println("YRAWAH HAHAHAHAHA  ");
      }
    }
  }

  //spider
  if (y == 4 && SPIDER == 0 && disq == 0) {
    Serial.println("30 🙂 ou ; 20");

    while (y == 4) {  // Serial.println(PUSHD);
      if (MAX == 1) {
        total = total + 30;
        y = 5;
        spider = 30;
        abaath();
        Serial.print("rak lamyt ");
        Serial.println(total);
      }

      if (MED == 1) {
        total = total + 20;
        y = 5;
        spider = 20;
        abaath();
        Serial.print("rak lamyt ");
        Serial.println(total);
      }
      if (PUSHD == 1) {
        disq = 1;
        y = 5;
        abaath();
        Serial.println("YRAWAH HAHAHAHAHA  ");
      }
    }
  }
  // fin
  if (y == 5 && FIN == 0 && disq == 0) {
    Serial.println("10 ou disq");

    while (y == 5) {  // Serial.println(PUSHD);



      if (MIN == 1)  // KEN WSEL W MAW9EFCH
      {
        total = total + 10;
        y = 6;
        fin = 10;
        abaath();
        Serial.print("rak lamyt ");
        Serial.println(total);
      }


      if (PUSHD == 1) {
        disq = 1;
        y = 6;
        abaath();
        Serial.println("YRAWAH HAHAHAHAHA  ");
      }
    }
  }
  if ((disq == 1) || y == 6) {

    wakt = (millis() - t3);
    abaath();
    // Reset values
    deb = hadh = anub = kbar = chams = spider = fin = total = disq = n1 = wakt = 0;
    t3 = 0;
    //id = -1;
    y = -1;
  }
}

void abaath_id() {
  sensor.clearTags();
  float floatWakt = wakt;  // Implicitly converted to float

  sensor.addField("deb", deb);
  sensor.addField("challenge1", hadh);
  sensor.addField("challenge2", anub);
  sensor.addField("challenge3", kbar);
  sensor.addField("challenge4", chams);
  sensor.addField("challenge5", spider);
  sensor.addField("fin", fin);
  sensor.addField("dis", disq);

  String id_str = String(id);
  sensor.addTag("id_robot", id_str);
  sensor.addField("temps_passe", wakt);
  sensor.addField("score", total);
  if (client.writePoint(sensor)) {
    Serial.println("Data written to InfluxDB");
  } else {
    Serial.print("Failed to write data to InfluxDB: ");
    Serial.println(client.getLastErrorMessage());
    while (true)
      ;
  }
}
void abaath() {
  float floatWakt = wakt;  // Implicitly converted to float

  
  sensor.addField("deb", deb);
  sensor.addField("challenge1", hadh);
  sensor.addField("challenge2", anub);
  sensor.addField("challenge3", kbar);
  sensor.addField("challenge4", chams);
  sensor.addField("challenge5", spider);
  sensor.addField("fin", fin);
  sensor.addField("dis", disq);

  //String id_str = String(id);
  //sensor.addTag("id_robot", id_str);
  sensor.addField("temps_passe", wakt);
  sensor.addField("score", total);
  if (client.writePoint(sensor)) {
    Serial.println("Data written to InfluxDB");
  } else {
    Serial.print("Failed to write data to InfluxDB: ");
    Serial.println(client.getLastErrorMessage());
    while (true)
      ;
  }
}
