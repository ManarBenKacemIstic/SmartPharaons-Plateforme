
async function fetchCSVFile(filePath) {
  try {
    const response = await fetch(filePath);
    if (!response.ok) {
      throw new Error(`Erreur lors du chargement du fichier : ${response.statusText}`);
    }
    const csvContent = await response.text();
    return csvContent;
  } catch (error) {
    console.error('Erreur lors de la récupération du fichier CSV :', error);
    throw error;
  }
}


function parseCSV(csvContent) {
  const rows = csvContent.split('\n').filter(row => row.trim() !== '');
  const headers = rows[0].split(',').map(header => header.trim());

  const data = rows.slice(1).map(row => {
    const values = row.split(',').map(value => value.trim());
    const obj = {};
    headers.forEach((header, index) => {
      obj[header] = values[index] || 'N/A';
    });
    return obj;
  });

  return data;
}


function displaySelectedFields(data, fieldsToDisplay) {
  const tableBody = document.querySelector('#data-table tbody');
  tableBody.innerHTML = '';
  const tableHeader = document.querySelector('#data-table thead tr');
  tableHeader.innerHTML = ''; 

  if (data.length > 0) {
    
    fieldsToDisplay.forEach(field => {
      const th = document.createElement('th');
      th.textContent = field;
      tableHeader.appendChild(th);
    });

    
    data.forEach(rowData => {
      const rowElement = document.createElement('tr');
      fieldsToDisplay.forEach(field => {
        const cell = document.createElement('td');
        cell.textContent = rowData[field] || 'N/A';
        rowElement.appendChild(cell);
      });
      tableBody.appendChild(rowElement);
    });
  } else {
    const rowElement = document.createElement('tr');
    const cell = document.createElement('td');
    cell.colSpan = fieldsToDisplay.length;
    cell.textContent = 'Aucune donnée disponible';
    rowElement.appendChild(cell);
    tableBody.appendChild(rowElement);
  }
}


async function loadCSVData() {
  try {
    const csvContent = await fetchCSVFile('./leaderboard.csv'); // Chemin vers le fichier CSV
    let data = parseCSV(csvContent);

    
    data = data.sort((a, b) => {
      const maxPointsA = parseFloat(a['Max Points']);
      const maxPointsB = parseFloat(b['Max Points']);
      const timeA = parseFloat(a['Time']);
      const timeB = parseFloat(b['Time']);

      
      if (maxPointsA !== maxPointsB) {
        return maxPointsB - maxPointsA; 
      }
      return timeA - timeB; 
    });

    
    const fieldsToDisplay = ['Leader_name', 'Robot_name', 'Max Points', 'Time'];
    displaySelectedFields(data, fieldsToDisplay);
  } catch (error) {
    console.error('Erreur lors du chargement des données :', error);
  }
}

window.onload = loadCSVData;
