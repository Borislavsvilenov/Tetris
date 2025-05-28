#ifndef BLOCK_HPP
#define BLOCK_HPP
#include <array>
#include <iostream>
#include <cmath>

#include <raylib.h>

#define LOG(x) std::cout << x << std::endl

class Block {
public:
    int x;
    int y;

    int state;

    std::array<int, 16> blockGrid;

    Block();

    void draw(int GameS, int GameX, int GameY) const;

    void rotate();
};



#endif //BLOCK_HPP
