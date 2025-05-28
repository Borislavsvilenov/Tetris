#ifndef UI_HPP
#define UI_HPP

#include <array>

#include "Element.hpp"
#include "../Game/Game.hpp"

class UI {
public:
    int CurrentScreen = 0;
    int frameCounter = 0;

    int ScreenWidth;
    int ScreenHeight;

    std::array<Element, 3> elements;

    int fontSize = 30;

    Vec2 mousePos;

    Game game;
    int GameS;
    int GameX;
    int GameY;


    UI(int w, int h);
    ~UI();

    void loop();
    void update();

    void drawElement(const Element& element) const;
    void drawGame() const;

    void buttonPressed(int i);
    void handleInput();
};

#endif //UI_HPP
