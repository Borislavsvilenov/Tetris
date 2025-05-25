#include "UI.hpp"

#include <cmath>
#include <raylib.h>

UI::UI(const int w, const int h) :
    ScreenWidth(w),
    ScreenHeight(h)
{
    elements[0] = Element({static_cast<float>(ScreenWidth / 2 - 100), 10}, {200, 40}, WHITE, BLUE, "TETRIS");

    InitWindow(ScreenWidth, ScreenHeight, "Tetris");
    SetTargetFPS(60);
}

UI::~UI() {
    CloseWindow();
}

void UI::loop() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        update();

        EndDrawing();

    }
}

void UI::update() {
    for (const Element& element : elements) {
        drawElement(element);
    }
}

void UI::drawElement(const Element& element) {
    const Rectangle boarder(element.pos.x, element.pos.y, element.size.x, element.size.y);
    DrawRectangleRounded(boarder, 0.8, 4, element.PColor); // The main Rectangle

    int Len = MeasureText(element.Text.c_str(), fontSize) / 2;
    Vec2 TextPos(element.size.x / 2 - Len + element.pos.x, element.pos.y + element.size.y / 2 - fontSize/2);
    DrawText(element.Text.c_str(), std::round(TextPos.x), std::round(TextPos.y), fontSize, element.SColor);
}

