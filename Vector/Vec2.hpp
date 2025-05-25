#ifndef VEC2_HPP
#define VEC2_HPP

struct Vec2 {
    float x, y;

    Vec2(float x,float y);
    Vec2();

    ~Vec2();

    Vec2 operator+(const Vec2& vec2) const;
    Vec2 operator-(const Vec2& vec2) const;
    Vec2 operator*(float scalar) const;
    Vec2 operator/(float scalar) const;

    Vec2& operator+=(const Vec2& vec2);
    Vec2& operator-=(const Vec2& vec2);
    Vec2& operator*=(float scalar);
    Vec2& operator/=(float scalar);

    [[nodiscard]] float size() const;
    [[nodiscard]] float dot(const Vec2& vec2) const;
};

#endif //VEC2_HPP
