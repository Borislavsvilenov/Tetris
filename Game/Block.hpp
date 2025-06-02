#ifndef BLOCK_HPP
#define BLOCK_HPP
#include <array>
#include <iostream>
#include <cmath>
#include <cstdlib>

#include <raylib.h>

#define LOG(x) std::cout << x << std::endl

class Block {
public:
    int x;
    int y;

    int rotationState;
    int blockType;

    std::array<int, 16> blockGrid;

    Block();

    void draw(int GameS, int GameX, int GameY) const;

    void newBlock();
    void rotate();
    void moveDown();
    void moveSide(int direction);
    void update();

    void Oblock();
    void Tblock();
    void Sblock();
    void Zblock();
    void Lblock();
    void Jblock();
    void Iblock();
};



#endif //BLOCK_HPP
