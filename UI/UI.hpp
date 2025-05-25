#ifndef UI_HPP
#define UI_HPP
#include <array>

#include "Element.hpp"

class UI {
public:
    int CurrentScreen = 0;

    int ScreenWidth;
    int ScreenHeight;

    std::array<Element, 3> elements;

    int fontSize = 30;

    UI(int w, int h);
    ~UI();

    void loop();
    void update();

    void drawElement(const Element& element);
};

#endif //UI_HPP
