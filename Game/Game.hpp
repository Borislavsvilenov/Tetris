#ifndef GAME_HPP
#define GAME_HPP
#include <array>


class Game {
public:
    bool running = false;
    bool moving = false;

    std::array<bool, 200> tiles;

    Game();
    ~Game();

    void start();
    void update(int frame);

    void spawnBlock();
    void spawnLong();

    void move();
};



#endif //GAME_HPP
