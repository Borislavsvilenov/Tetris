#ifndef GAME_HPP
#define GAME_HPP
#include <raylib.h>
#include <cmath>
#include <array>

#include "Block.hpp"

#define LOG(x) std::cout << x << std::endl

class Game {
public:
    bool running = false;
    bool moving = false;

    std::array<int, 200> tiles;

    Block* block = {};

    Game();
    ~Game();

    void start();
    void reset();
    void update(int frame);

    void spawnBlock();
    void stopBlock();
    void checkCollision();
    void move();

    void draw(int GameS, int GameX, int GameY) const;
};



#endif //GAME_HPP
