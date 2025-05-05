#include "WaveAlgorithm.h"

MyMap MapReader::readMapFromFile(const std::string& filePath) {
    std::vector<char> grid;
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return MyMap({}, 0, 0);
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
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;
    }
    const auto& grid = map.getGrid();
    int mapHeight = map.getMapHeight();
    int mapWeight = map.getMapWeight();

    for (int i = 0; i < mapHeight; ++i) {
        for (int j = 0; j < mapWeight; ++j) {
            outFile << grid[i * mapWeight + j] << " ";
        }
        outFile << std::endl;
    }

    outFile.close();
};


MyMap::MyMap(const std::vector<char>& grid, int mapWeight, int mapHeight): grid(grid), mapWeight(mapWeight), mapHeight(mapHeight){};

MyMap::MyMap(const MyMap& other): grid(other.grid), mapWeight(other.mapWeight), mapHeight(other.mapHeight) {};

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

const std::vector<char>& MyMap::getGrid() const {
    return grid;
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
        std::cout << "Hero or exit not found!" << std::endl;
        return;
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
    return;
};
