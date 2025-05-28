#include "Block.hpp"



Block::Block() : x(0), y(0), state(0)
{
    blockGrid.fill(1);
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
                DrawRectangle(GameS * (x + (i % 4)) + GameX, GameS * ((std::floor(i / 4)) + y) + GameY, GameS, GameS, BLACK);
                break;
        }
    }
}

void Block::rotate() {
    if (state == 3) {
        state = 0;
    } else {
        state++;
    }
}



