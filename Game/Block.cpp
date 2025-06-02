#include "Block.hpp"



Block::Block() : x(0), y(0), rotationState(0), blockType(0)
{
    blockGrid.fill(0);
    blockType = 0;
}

void Block::newBlock() {
    blockGrid.fill(0);
    blockType = (rand() % 6) + 1;
    x = 4;
    y = 0;
}

void Block::draw(const int GameS, const int GameX, const int GameY) const {
    for (int i = 0; i < blockGrid.size(); i++) {
        switch (blockGrid[i]) {
            case 1:
                DrawRectangle(GameS * (x + (i % 4)) + GameX, GameS * ((std::floor(i / 4)) + y) + GameY, GameS, GameS, RED);
                break;
            case 2:
                DrawRectangle(GameS * (x + (i % 4)) + GameX, GameS * ((std::floor(i / 4)) + y) + GameY, GameS, GameS, YELLOW);
                break;
            case 3:
                DrawRectangle(GameS * (x + (i % 4)) + GameX, GameS * ((std::floor(i / 4)) + y) + GameY, GameS, GameS, SKYBLUE);
                break;
            case 4:
                DrawRectangle(GameS * (x + (i % 4)) + GameX, GameS * ((std::floor(i / 4)) + y) + GameY, GameS, GameS, PURPLE);
                break;
            case 5:
                DrawRectangle(GameS * (x + (i % 4)) + GameX, GameS * ((std::floor(i / 4)) + y) + GameY, GameS, GameS, GREEN);
                break;
            case 6:
                DrawRectangle(GameS * (x + (i % 4)) + GameX, GameS * ((std::floor(i / 4)) + y) + GameY, GameS, GameS, BLUE);
                break;
            case 7:
                DrawRectangle(GameS * (x + (i % 4)) + GameX, GameS * ((std::floor(i / 4)) + y) + GameY, GameS, GameS, LIGHTGRAY);
                break;
            default:
                break;
        }
    }
}

void Block::rotate() {
    if (rotationState == 3) {
        rotationState = 0;
    } else {
        rotationState++;
    }
}

void Block::moveDown() {
    y++;
}

void Block::moveSide(const int direction) {
    x += direction;
}

void Block::update() {
    blockGrid.fill(0);
    switch (blockType) {
        case 1:
            Oblock();
            break;
        case 2:
            Tblock();
            break;
        case 3:
            Sblock();
            break;
        case 4:
            Zblock();
            break;
        case 5:
            Lblock();
            break;
        case 6:
            Jblock();
            break;
        case 7:
            Iblock();
            break;
        default:
            break;
    }
}

void Block::Oblock() {
    blockGrid[0] = 1;
    blockGrid[1] = 1;
    blockGrid[4] = 1;
    blockGrid[5] = 1;
}

void Block::Tblock() {
    switch (rotationState) {
        case 0:
            blockGrid[1] = 2;
            blockGrid[4] = 2;
            blockGrid[5] = 2;
            blockGrid[6] = 2;
            break;
        case 1:
            blockGrid[1] = 2;
            blockGrid[5] = 2;
            blockGrid[6] = 2;
            blockGrid[9] = 2;
            break;
        case 2:
            blockGrid[4] = 2;
            blockGrid[5] = 2;
            blockGrid[6] = 2;
            blockGrid[9] = 2;
            break;
        case 3:
            blockGrid[1] = 2;
            blockGrid[4] = 2;
            blockGrid[5] = 2;
            blockGrid[9] = 2;
            break;
    }
}

void Block::Sblock() {
    switch (rotationState) {
        case 0:
        case 2:
            blockGrid[1] = 3;
            blockGrid[2] = 3;
            blockGrid[4] = 3;
            blockGrid[5] = 3;
            break;
        case 1:
        case 3:
            blockGrid[0] = 3;
            blockGrid[4] = 3;
            blockGrid[5] = 3;
            blockGrid[9] = 3;
            break;
    }
}

void Block::Zblock() {
    switch (rotationState) {
        case 0:
        case 2:
            blockGrid[0] = 4;
            blockGrid[1] = 4;
            blockGrid[5] = 4;
            blockGrid[6] = 4;
            break;
        case 1:
        case 3:
            blockGrid[1] = 4;
            blockGrid[4] = 4;
            blockGrid[5] = 4;
            blockGrid[8] = 4;
            break;
    }
}

void Block::Lblock() {
    switch (rotationState) {
        case 0:
            blockGrid[2] = 5;
            blockGrid[4] = 5;
            blockGrid[5] = 5;
            blockGrid[6] = 5;

            break;
        case 1:
            blockGrid[1] = 5;
            blockGrid[5] = 5;
            blockGrid[9] = 5;
            blockGrid[10] = 5;
            break;
        case 2:
            blockGrid[4] = 5;
            blockGrid[5] = 5;
            blockGrid[6] = 5;
            blockGrid[8] = 5;
            break;
        case 3:
            blockGrid[0] = 5;
            blockGrid[1] = 5;
            blockGrid[5] = 5;
            blockGrid[9] = 5;
            break;
    }
}

void Block::Jblock() {
    switch (rotationState) {
        case 0:
            blockGrid[4] = 6;
            blockGrid[5] = 6;
            blockGrid[6] = 6;
            blockGrid[8] = 6;
            break;
        case 1:
            blockGrid[0] = 6;
            blockGrid[1] = 6;
            blockGrid[5] = 6;
            blockGrid[9] = 6;
            break;
        case 2:
            blockGrid[2] = 6;
            blockGrid[4] = 6;
            blockGrid[5] = 6;
            blockGrid[6] = 6;

            break;
        case 3:
            blockGrid[1] = 6;
            blockGrid[5] = 6;
            blockGrid[9] = 6;
            blockGrid[10] = 6;

            break;
    }
}

void Block::Iblock() {
    switch (rotationState) {
        case 0:
            blockGrid[4] = 7;
            blockGrid[5] = 7;
            blockGrid[6] = 7;
            blockGrid[7] = 7;
            break;
        case 1:
            blockGrid[2] = 7;
            blockGrid[6] = 7;
            blockGrid[10] = 7;
            blockGrid[14] = 7;
            break;
        case 2:
            blockGrid[8] = 7;
            blockGrid[9] = 7;
            blockGrid[10] = 7;
            blockGrid[11] = 7;
            break;
        case 3:
            blockGrid[1] = 7;
            blockGrid[5] = 7;
            blockGrid[9] = 7;
            blockGrid[13] = 7;
            break;
    }
}









