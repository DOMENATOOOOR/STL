#include "WaveAlgorithm.h"

int main() {
    MyMap myMap = MapReader::readMapFromFile("/Users/mac_aleksandr/mymap.txt");
    myMap.waveAlgorithm();
    MapReader::writeMapToFile("updated_map.txt", myMap);

}