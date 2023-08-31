#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

const int MAX_ROWS = 100;
const int MAX_COLUMNS = 4;

int main() {
    std::ifstream inputFile("meteo.csv");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    std::string headers[MAX_COLUMNS];
    std::string data[MAX_ROWS][MAX_COLUMNS];
    int numRows = 0;

    // Read the header line
    if (std::getline(inputFile, line)) {
        std::istringstream headerStream(line);
        std::string header;
        int columnIndex = 0;
        while (std::getline(headerStream, header, ',') && columnIndex < MAX_COLUMNS) {
            headers[columnIndex++] = header;
        }
    }

    // Read data lines
    while (std::getline(inputFile, line) && numRows < MAX_ROWS) {
        std::istringstream dataStream(line);
        std::string value;
        int columnIndex = 0;
        while (std::getline(dataStream, value, ',') && columnIndex < MAX_COLUMNS) {
            data[numRows][columnIndex++] = value;
        }
        numRows++;
    }

    // Close the file
    inputFile.close();

    // Display headers
    for (int i = 0; i < MAX_COLUMNS; ++i) {
        std::cout << headers[i] << "\t";
    }
    std::cout << std::endl;

    // Display data
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < MAX_COLUMNS; ++j) {
            std::cout << data[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
