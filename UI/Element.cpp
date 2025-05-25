#include "Element.hpp"

#include <utility>

Element::Element(const Vec2& p, const Vec2& s, const Color pcol, const Color scol, std::string text) :
    pos(p),
    size(s),
    PColor(pcol),
    SColor(scol),
    Text(std::move(text)),
    visible(true)
{

}

Element::Element() : PColor(WHITE), SColor(BLACK), visible(false)
{

}

bool Element::hovered(const Vec2& mousePos) const {
    return mousePos.x >= pos.x
        && mousePos.x < pos.x + size.x
        && mousePos.y >= pos.y
        && mousePos.y < pos.y + size.y
        && visible;
}


