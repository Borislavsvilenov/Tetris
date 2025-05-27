#include "Game.hpp"



Game::Game() {

}

Game::~Game() {
    block1 = nullptr;
    block2 = nullptr;
    block3 = nullptr;
    block4 = nullptr;
}

void Game::start() {
    running = true;
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
    spawnLong();
}

void Game::spawnLong() {
    tiles[3].state = true;
    tiles[4].state = true;
    tiles[5].state = true;
    tiles[6].state = true;

    block1 = &tiles[3];
    block2 = &tiles[4];
    block3 = &tiles[5];
    block4 = &tiles[6];
}

void Game::move() {

}



