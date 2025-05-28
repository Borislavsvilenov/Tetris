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
    if (frame % 20 != 0) {
        return;
    }

    if (!moving) {
        spawnBlock();
    } else {
        move();
    }
}

void Game::spawnBlock() {

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


