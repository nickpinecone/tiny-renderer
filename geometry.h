#pragma once

#include <cmath>
#include <array>

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

    double at(int index) {
        auto arr = std::array<double, 2>{x, y};
        return arr[index];
    }
};

struct Vec3 {
    double x, y, z;

    Vec3(const double x, const double y, const double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vec3 operator -(const Vec3 &other) const {
        return Vec3{this->x - other.x, this->y - other.y, this->z - other.z};
    }

    Vec3 operator +(const Vec3 &other) const {
        return Vec3{this->x + other.x, this->y + other.y, this->z + other.z};
    }

    Vec3 normalized() const {
        const auto length = this->length();
        return Vec3{this->x / length, this->y / length, this->z / length};
    }

    double length() const {
        return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2) + std::pow(this->z, 2));
    }

    double at(int index) {
        auto arr = std::array<double, 3>{x, y, z};
        return arr[index];
    }
};
