#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include <string>

#include "raylib.h"
#include "../Vector/Vec2.hpp"

class Element {
public:
    Vec2 pos, size;

    Color PColor;
    Color SColor;

    std::string Text;

    bool visible;

    Element(const Vec2& p, const Vec2& s, Color pcol, Color scol, std::string  text);
    Element();
    ~Element() = default;

    [[nodiscard]] bool hovered(const Vec2& mousePos) const;
};

#endif //ELEMENT_HPP
