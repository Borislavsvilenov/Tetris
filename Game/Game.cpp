#include "Game.hpp"



Game::Game() {

}

Game::~Game() {

}

void Game::start() {
    for (int i = 0; i < tiles.size(); i++) {
        tiles[i] = false;
    }
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
    moving = true;
    spawnLong();
}

void Game::spawnLong() {
    tiles[3] = true;
    tiles[4] = true;
    tiles[5] = true;
    tiles[6] = true;
}

void Game::move() {
    bool moved = false;

    for (int i = tiles.size() - 11; i >= 0; i--) {
        if (tiles[i] && !tiles[i+10]) {
            tiles[i] = false;
            tiles[i+10] = true;
            moved = true;
        }
    }

    if (!moved) {
        moving = false;
    }
}



