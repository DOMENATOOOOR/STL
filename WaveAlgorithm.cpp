#include "WaveAlgorithm.h"

MyMap::MyMap(const std::vector<char>& grid, int mapWeight, int mapHeight): grid(grid), mapWeight(mapWeight), mapHeight(mapHeight){};

MyMap::MyMap(const MyMap& other): grid(other.grid), mapWeight(other.mapWeight), mapHeight(other.mapHeight) {}

int MyMap::findHero() const{
    for (int y = 0; y < mapHeight; ++y) {
        for (int x = 0; x < mapWeight; ++x) {
            if (grid[y * mapWeight + x] == '2') {
                return y * mapWeight + x;
            }
        }
    }
    return -1;
}


int MyMap::findExit() const{
    for (int y = 0; y < mapHeight; ++y) {
        for (int x = 0; x < mapWeight; ++x) {
            if (grid[y * mapWeight + x] == '3') {
                return y * mapWeight + x;
            }
        }
    }
    return -1;
}

int MyMap::getMapWeight() const {
    return mapWeight;
}

int MyMap::getMapHeight() const {
    return mapHeight;
}

bool MyMap::isWalkable(int x, int y ) const {
    if (x < 0 || x >= mapWeight || y < 0 || y >= mapHeight) {
        return false;
    }
    char cell = grid[y * mapWeight + x];
    return cell == '0' || cell == '3';
}

void MyMap::waveAlgorithm() {
    int heroPos = findHero();
    int exitPos = findExit();

    if (heroPos == -1 || exitPos == -1) {
        throw std::runtime_error("No hero or exit found");
    }

    std::queue<int> q;
    q.push(heroPos);

    std::unordered_map<int, bool> visited;
    visited[heroPos] = true;

    std::unordered_map<int, int> parent;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == exitPos) {
            std::vector<int> path;
            for (int step = current; step != heroPos; step = parent[step]) {
                path.push_back(step);
            }
            path.push_back(heroPos);

            for (int index : path) grid[index] = '*';
            return;
        }

        for (const auto& direction : directions) {
            int newX = (current % mapWeight) + direction.first;
            int newY = (current / mapWeight) + direction.second;

            if (isWalkable(newX, newY)) {
                int newIndex = newY * mapWeight + newX;
                if (!visited[newIndex]) {
                    visited[newIndex] = true;
                    parent[newIndex] = current;
                    q.push(newIndex);
                }
            }
        }
    }
};
