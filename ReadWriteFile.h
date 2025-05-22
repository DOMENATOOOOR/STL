#pragma once
#include "WaveAlgorithm.h"

class MapReader {
public:
    static MyMap readMapFromFile(const std::string& filePath);
    static void writeMapToFile(const std::string& filePath, const MyMap& Map);
};
