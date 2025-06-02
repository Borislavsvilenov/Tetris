#include "Game.hpp"

#include <iostream>


Game::Game() {
    tiles.fill(0);
    block = new Block();
}

Game::~Game() {

}

void Game::start() {
    running = true;
}

void Game::reset() {
    tiles.fill(0);
    moving = false;
}

void Game::update(int frame) {
    if (!running) {
        return;
    }

    block->update();

    if (frame % 20 != 0) {
        return;
    }

    if (!moving) {
        spawnBlock();
        moving = true;
    } else {
        block->moveDown();
        stopBlock();
    }
}

void Game::spawnBlock() {
    block->newBlock();
}

void Game::stopBlock() {
    for (int i = 0; i < block->blockGrid.size(); i++) {
        if (block->blockGrid[i] > 0) {
            int gridX = block->x + (i % 4);
            int gridY = block->y + (floor(i / 4));
            tiles[gridX + 10 * gridY] = block->blockGrid[i];
        }
    }
    moving = false;
}

void Game::checkCollision() {
    if (block->y < 16) {
        return;
    }

    if (block->blockGrid[15] == 0 && block->blockGrid[14] == 0 && block->blockGrid[13] == 0 && block->blockGrid[12] == 0) {
        if (block->y == 16) {
            return;
        }
    }

    if (block->blockGrid[11] == 0 && block->blockGrid[10] == 0 && block->blockGrid[9] == 0 && block->blockGrid[8] == 0) {
        if (block->y == 17) {
            return;
        }
    }

    stopBlock();
}

void Game::move() {

}

void Game::draw(const int GameS, const int GameX, const int GameY) const {
    for (int i = 0; i < tiles.size(); i++) {
        switch (tiles[i]) {
            case 1:
                DrawRectangle(GameS * (i % 10) + GameX, GameS * (std::floor(i / 10)) + GameY, GameS, GameS, RED);
                break;
            case 2:
                DrawRectangle(GameS * (i % 10) + GameX, GameS * (std::floor(i / 10)) + GameY, GameS, GameS, YELLOW);
                break;
            case 3:
                DrawRectangle(GameS * (i % 10) + GameX, GameS * (std::floor(i / 10)) + GameY, GameS, GameS, SKYBLUE);
                break;
            case 4:
                DrawRectangle(GameS * (i % 10) + GameX, GameS * (std::floor(i / 10)) + GameY, GameS, GameS, PURPLE);
                break;
            case 5:
                DrawRectangle(GameS * (i % 10) + GameX, GameS * (std::floor(i / 10)) + GameY, GameS, GameS, GREEN);
                break;
            case 6:
                DrawRectangle(GameS * (i % 10) + GameX, GameS * (std::floor(i / 10)) + GameY, GameS, GameS, BLUE);
                break;
            case 7:
                DrawRectangle(GameS * (i % 10) + GameX, GameS * (std::floor(i / 10)) + GameY, GameS, GameS, LIGHTGRAY);
                break;
            default:
                DrawRectangle(GameS * (i % 10) + GameX, GameS * (std::floor(i / 10)) + GameY, GameS, GameS, BLACK);
                break;
        }
    }
}


