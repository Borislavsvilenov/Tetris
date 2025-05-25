#include "Vec2.hpp"
#include <cmath>

Vec2::Vec2(const float x, const float y) : x(x), y(y) {}
Vec2::Vec2() : x(0), y(0) {}

Vec2::~Vec2() = default;

Vec2 Vec2::operator+(const Vec2& vec2) const {
    return {x + vec2.x, y + vec2.y};
}

Vec2 Vec2::operator-(const Vec2& vec2) const {
    return {x - vec2.x, y - vec2.y};
}

Vec2 Vec2::operator*(const float scalar) const {
    return {x * scalar, y * scalar};
}

Vec2 Vec2::operator/(const float scalar) const {
    return {x / scalar, y / scalar};
}

Vec2& Vec2::operator+=(const Vec2& vec2) {
    x += vec2.x;
    y += vec2.y;
    return *this;
}

Vec2& Vec2::operator-=(const Vec2& vec2) {
    x -= vec2.x;
    y -= vec2.y;
    return *this;
}

Vec2& Vec2::operator*=(const float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vec2& Vec2::operator/=(const float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

float Vec2::size() const {
    return std::sqrt(x * x + y * y);
}

float Vec2::dot(const Vec2& vec2) const {
    return x * vec2.x + y * vec2.y;
}



