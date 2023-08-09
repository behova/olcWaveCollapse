// build tiles
#include "tiles.h"
#include "json.hpp"
#include <array>
#include <fstream>
#include <iostream>

using namespace std;

void Tiles::initTiles() {
  ifstream jsonFile("../assets/Tilesheet_tiles.json");
  nlohmann::json jTiles = nlohmann::json::parse(jsonFile);

  // std::cout << std::setw(2) << jTiles;

  int i = 0;

  for (auto it = jTiles.begin(); it != jTiles.end(); ++it) {
    Tile newtile;
    newtile.name = it.value()["name"].get<std::string>();
    newtile.hasRotation = it.value()["hasRotation"].get<bool>();
    newtile.edges = it.value()["edges"].get<std::array<std::string, 4>>();
    tiles[i] = newtile;
    i += 1;
  }
}

void Tiles::printTileData() {
  int i, j;
  for (i = 0; i < 36; i++) {
    std::cout << "name: \n";
    std::cout << tiles[i].name;
    std::cout << "\n";
    std::cout << "hasRotation: \n";
    std::cout << tiles[i].hasRotation;
    std::cout << "\n";
    std::cout << "edges: \n";
    for (j = 0; j < 4; j++) {
      std::cout << tiles[i].edges[j];
      std::cout << "\n";
    }
    std::cout << "\n";
  }
}
