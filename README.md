# SmartPharaons-Plateforme

Notre plateforme permet de suivre en temps réel la progression des robots lors des compétitions de robotique. Grâce à un affichage dynamique et interactif, elle fournit des informations essentielles sur chaque robot en compétition et permet une visualisation immersive de l’événement.

## Fonctionnalités

### 🔹 Informations en temps réel :
- *Nom du robot et leader de l’équipe* : Suivi de l’équipe et de son robot tout au long de la compétition.
- *Chronomètre précis* : Affichage du temps écoulé avec une précision en secondes et millisecondes.
- *Score mis à jour instantanément* : Le score des robots est actualisé en temps réel.

### 🔹 Suivi du parcours sur la maquette :
- *Suivi dynamique sur la maquette* : Les robots évoluent sur une maquette équipée de capteurs qui envoient leur position en temps réel à une base de données InfluxDB.
- *Affichage SVG interactif* : L’interface utilise une image SVG de la maquette et colorie dynamiquement les zones parcourues par chaque robot à mesure qu’il termine un challenge.

## Technologies utilisées

### 🔧 Node.js :
Environnement d'exécution JavaScript pour la création du serveur.

### 🔧 Express :
Framework pour créer l'API backend et gérer les requêtes HTTP.

### 🔧 InfluxDB :
Base de données utilisée pour stocker et récupérer les données de position des robots en temps réel.

### 🔧 HTML/CSS :
Structure et style de l'interface utilisateur.

### 🔧 JavaScript :
Utilisé pour l'interactivité et la mise à jour en temps réel des informations sur l'interface.

### 🔧 SVG :
Format graphique utilisé pour afficher et suivre les parcours des robots sur la maquette.
