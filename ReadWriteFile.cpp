#include "WaveAlgorithm.h"
#include "ReadWriteFile.h"
#include <fstream>

MyMap MapReader::readMapFromFile(const std::string& filePath) {
    std::vector<char> grid;
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + filePath);
    }
    std::string line;
    int mapHeight = 0;
    while (std::getline(file, line)) {
        for (char value : line) {
            if (value != ' ') {
                grid.push_back(value);
            }
        }
        ++mapHeight;
    }

    int mapWeight = grid.size() / mapHeight;
    file.close();

    return MyMap(grid, mapWeight, mapHeight);
};

void MapReader::writeMapToFile(const std::string& filePath, const MyMap& map) {
    std::ofstream outFile(filePath);
    if (!outFile) {
        throw std::runtime_error("Could not open file " + filePath);
    }
    for (char it : map) {
        outFile << it << " ";
    }

    outFile.close();
}
