#pragma once
#include <map>
#include <queue>

class MyMap {
    const std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    std::vector<char> grid;
    int mapWeight = 0;
    int mapHeight = 0;
    [[nodiscard]] int findHero() const;
    [[nodiscard]] int findExit() const;
    [[nodiscard]] bool isWalkable(int x, int y ) const;
public:
    MyMap(const std::vector<char>& grid, int mapWeight, int mapHeight);
    MyMap(const MyMap& other);
    [[nodiscard]] auto begin() const {
        return grid.begin();
    }
    [[nodiscard]] auto end() const {
        return grid.end();
    }
    [[nodiscard]] int getMapWeight() const;
    [[nodiscard]] int getMapHeight() const;
    void waveAlgorithm();
};
