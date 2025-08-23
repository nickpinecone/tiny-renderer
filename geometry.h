#pragma once

#include <cmath>

struct Vec2 {
    double x, y;

    Vec2(const double x, const double y) {
        this->x = x;
        this->y = y;
    }

    Vec2 operator -(const Vec2 &other) const {
        return Vec2{this->x - other.x, this->y - other.y};
    }

    Vec2 operator +(const Vec2 &other) const {
        return Vec2{this->x + other.x, this->y + other.y};
    }

    Vec2 normalized() const {
        const auto length = this->length();
        return Vec2{this->x / length, this->y / length};
    }

    double length() const {
        return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2));
    }
};
