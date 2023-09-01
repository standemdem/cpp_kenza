// # Correction - Lecture de données météorologiques

// ```cpp
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// #include <vector>

// using namespace std;

// int main() {
//     ifstream fichier("donnees_meteo.csv"); // Assurez-vous que le fichier existe dans le répertoire de votre projet.

//     if (!fichier) {
//         cerr << "Erreur lors de l'ouverture du fichier." << endl;
//         return 1;
//     }

//     string ligne;
//     getline(fichier, ligne); // Lire la ligne d'en-tête et la jeter.

// 		int jours = 0;
//     double sommeTempMin = 0.0;
//     double sommeTempMax = 0.0;
//     double sommePrecipitation = 0.0;

//     while (getline(fichier, ligne)) {
//         stringstream ss(ligne);
//         string jour, tempMin, tempMax, precipitation;

//         getline(ss, jour, ',');
//         getline(ss, tempMin, ',');
//         getline(ss, tempMax, ',');
//         getline(ss, precipitation);

//         // Convertir les valeurs en nombres
//         int jourInt = stoi(jour);
//         double tempMinDouble = stod(tempMin);
//         double tempMaxDouble = stod(tempMax);
//         double precipitationDouble = stod(precipitation);

//         // Calculer les sommes
//         sommeTempMin += tempMinDouble;
//         sommeTempMax += tempMaxDouble;
//         sommePrecipitation += precipitationDouble;

//         jours++;
//     }

//     if (jours == 0) {
//         cerr << "Aucune donnée n'a été trouvée dans le fichier." << endl;
//         return 1;
//     }

//     double tempMinMoyenne = sommeTempMin / jours;
//     double tempMaxMoyenne = sommeTempMax / jours;

//     cout << "Statistiques pour le mois :" << endl;
//     cout << "Température minimale moyenne : " << tempMinMoyenne << " degrés Celsius" << endl;
//     cout << "Température maximale moyenne : " << tempMaxMoyenne << " degrés Celsius" << endl;
//     cout << "Total des précipitations pour le mois : " << sommePrecipitation << " mm" << endl;

//     fichier.close();
//     return 0;
// }
// ```

// Correction 2 :

// ```cpp
// #include <iostream>
// #include <fstream>
// #include <string>

// using namespace std;

// int main() {
//     ifstream fichier("donnees_meteo.csv"); // Assurez-vous que le fichier existe dans le répertoire de votre projet.

//     if (!fichier) {
//         cerr << "Erreur lors de l'ouverture du fichier." << endl;
//         return 1;
//     }

//     string ligne;
//     getline(fichier, ligne); // Lire la ligne d'en-tête et la jeter.

//     int jours = 0;
//     double sommeTempMin = 0.0;
//     double sommeTempMax = 0.0;
//     double sommePrecipitation = 0.0;

//     while (getline(fichier, ligne)) {
//         // Recherche des délimiteurs (',') dans la ligne
//         size_t pos = ligne.find(',');
//         if (pos == string::npos) {
//             cerr << "Format de ligne incorrect dans le fichier." << endl;
//             return 1;
//         }

//         string jourStr = ligne.substr(0, pos);
//         ligne.erase(0, pos + 1);

//         pos = ligne.find(',');
//         if (pos == string::npos) {
//             cerr << "Format de ligne incorrect dans le fichier." << endl;
//             return 1;
//         }

//         string tempMinStr = ligne.substr(0, pos);
//         ligne.erase(0, pos + 1);

//         pos = ligne.find(',');
//         if (pos == string::npos) {
//             cerr << "Format de ligne incorrect dans le fichier." << endl;
//             return 1;
//         }

//         string tempMaxStr = ligne.substr(0, pos);
//         string precipitationStr = ligne.substr(pos + 1); // La dernière valeur

//         // Extraction des valeurs
//         int jourInt = stoi(jourStr);
//         double tempMinDouble = stod(tempMinStr);
//         double tempMaxDouble = stod(tempMaxStr);
//         double precipitationDouble = stod(precipitationStr);

//         // Calcul des sommes
//         sommeTempMin += tempMinDouble;
//         sommeTempMax += tempMaxDouble;
//         sommePrecipitation += precipitationDouble;

//         jours++;
//     }

//     if (jours == 0) {
//         cerr << "Aucune donnée n'a été trouvée dans le fichier." << endl;
//         return 1;
//     }

//     double tempMinMoyenne = sommeTempMin / jours;
//     double tempMaxMoyenne = sommeTempMax / jours;

//     cout << "Statistiques pour le mois :" << endl;
//     cout << "Température minimale moyenne : " << tempMinMoyenne << " degrés Celsius" << endl;
//     cout << "Température maximale moyenne : " << tempMaxMoyenne << " degrés Celsius" << endl;
//     cout << "Total des précipitations pour le mois : " << sommePrecipitation << " mm" << endl;

//     fichier.close();
//     return 0;
// }
// ```

// Exemple stringstream :

// ```cpp
// #include <iostream>
// #include <sstream>

// int main() {
//     // Vers string
//     int myInt = 42;
//     std::stringstream ss;
//     ss << myInt;
//     std::string myString = ss.str();
//     std::cout << "myString = " << myString << std::endl;
    
//     // Vers int
//     std::string myString2 = "12345";
//     int myInt2;
//     std::stringstream ss2(myString2);
//     ss2 >> myInt2;
//     std::cout << "myInt = " << myInt2 << std::endl;
//     return 0;
// }
// ```