
#include "olcPixelGameEngine.h"
#include "tiles.h"
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>

class Engine : public olc::PixelGameEngine {
public:
  Engine() { sAppName = "Tetris"; };

private:
  int tileRows, tileColumns;
  int spriteSize;
  std::unique_ptr<olc::Sprite> sprTileSheet;

public:
  bool OnUserCreate() override {
    // Called once at the start, so create things here
    // set rows and columns
    tileColumns = 12;
    tileRows = 10;
    spriteSize = 16;

    sprTileSheet = std::make_unique<olc::Sprite>("../assets/Tilemap/tiles.png");

    tiles.initTiles();
    tiles.printTileData();

    return true;
  }

  bool OnUserUpdate(float fElapsedTime) override

  /* start game loop*/
  {
    int i, j;

    for (i = 0; i < tileColumns + 1; i++) {
      for (j = 0; j < tileRows + 1; j++)
        Engine::DrawPartialSprite(i * spriteSize, j * spriteSize,
                                  sprTileSheet.get(), i * spriteSize,
                                  j * spriteSize, 16, 16, 1);
    }

    return true;
  }

protected:
  Tiles tiles;
};

int main() {
  Engine window;
  // Construct ScreenWidth, ScreenHeight, pixelW, pixelH
  if (window.Construct(256, 240, 4, 4))
    window.Start();

  return 0;
}
