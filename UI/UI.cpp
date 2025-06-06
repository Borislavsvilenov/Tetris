#include "UI.hpp"

#include <cmath>
#include <iostream>
#include <raylib.h>

#define LOG(x) std::cout << x << std::endl
#define DARK CLITERAL(Color){ 30, 30, 30, 255 }

#define castF static_cast<float>


UI::UI(const int w, const int h) : ScreenWidth(w),
                                   ScreenHeight(h),
                                   GameS(40),
                                   GameX(ScreenWidth / 2 - GameS * 5),
                                   GameY(60)
{
    elements[0] = Element({castF(ScreenWidth / 2 - 100), 10}, {200, 40}, DARK, GREEN, "TETRIS");
    elements[1] = Element({castF(ScreenWidth / 2 - 100), 300}, {200, 40}, BLACK, GREEN, "PLAY");

    InitWindow(ScreenWidth, ScreenHeight, "Tetris");
    SetTargetFPS(60);
}

UI::~UI() {
    CloseWindow();
}

void UI::loop() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARK);

        update();
        frameCounter++;
        if (frameCounter == 60) {
            frameCounter = 0;
        }

        EndDrawing();

    }
}

void UI::update() {
    for (const Element& element : elements) {
        drawElement(element);
    }
    drawGame();

    handleInput();

    game.update(frameCounter);
}

void UI::drawElement(const Element& element) const {
    if (!element.visible) {
        return;
    }

    const Rectangle boarder(element.pos.x, element.pos.y, element.size.x, element.size.y);
    DrawRectangleRounded(boarder, 0.8, 4, element.PColor); // The main Rectangle

    int Len = MeasureText(element.Text.c_str(), fontSize) / 2;
    Vec2 TextPos(element.size.x / 2 - Len + element.pos.x, element.pos.y + element.size.y / 2 - fontSize/2);
    DrawText(element.Text.c_str(), std::round(TextPos.x), std::round(TextPos.y), fontSize, element.SColor);
}

void UI::drawGame() const {
    if (!game.running) {
        return;
    }
    game.draw(GameS, GameX, GameY);
    game.block->draw(GameS, GameX, GameY);
}

void UI::buttonPressed(const int i) {
    if (elements[i].hovered(mousePos)) {
        switch (i) {
            case 0:

                break;
            case 1:

                elements[1].visible = false;
                elements[2].visible = false;
                game.start();
            case 2:

                break;
            default:

                break;
        }
    }
}


void UI::handleInput() {
    mousePos = {castF(GetMouseX()), castF(GetMouseY())};

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        for (int i = 0; i < elements.size(); i++) {
            buttonPressed(i);
        }
    }

    if (IsKeyPressed(KEY_UP)) {
        game.block->rotate();
    }
}

