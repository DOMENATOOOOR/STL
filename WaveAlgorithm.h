#pragma once
#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <fstream>
#include <queue>
#include <sstream>


class MyMap {
private:
    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//вверх, вниз, влево, вправо
    std::vector<char> grid;
    int mapWeight = 0;
    int mapHeight = 0;
public:
    MyMap(const std::vector<char>& grid, int mapWeight, int mapHeight);
    MyMap(const MyMap& other);
    int findHero() const;
    int findExit() const;
    int getMapWeight() const;
    int getMapHeight() const;
    bool isWalkable(int x, int y ) const;
    void waveAlgorithm();
    const std::vector<char>& getGrid() const;
};

class MapReader {
public:
    static MyMap readMapFromFile(const std::string& filePath);
    static void writeMapToFile(const std::string& filePath, const MyMap& Map);
};