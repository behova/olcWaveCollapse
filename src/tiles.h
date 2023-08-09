#ifndef TILES_H_
#define TILES_H_

#include <array>
#include <string>

// Single tile struct
struct Tile {
  std::string name;
  bool hasRotation;
  std::array<std::string, 4> edges;
};

// initializes array of tile structs from JSON file
class Tiles {
public:
  std::array<Tile, 36> tiles;

  void initTiles();
  void printTileData();
};

#endif
