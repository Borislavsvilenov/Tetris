#ifndef GAME_HPP
#define GAME_HPP
#include <array>

#include "Tiles.h"


class Game {
public:
    bool running = false;
    bool moving = false;

    Tiles* block1 = {};
    Tiles* block2 = {};
    Tiles* block3 = {};
    Tiles* block4 = {};

    std::array<Tiles, 200> tiles;

    Game();
    ~Game();

    void start();
    void update(int frame);

    void spawnBlock();
    void spawnLong();

    void move();
};



#endif //GAME_HPP
