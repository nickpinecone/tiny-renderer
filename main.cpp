#include <cmath>
#include "tgaimage.h"
#include "geometry.h"

constexpr TGAColor white = {255, 255, 255, 255}; // attention, BGRA order
constexpr TGAColor green = {0, 255, 0, 255};
constexpr TGAColor red = {0, 0, 255, 255};
constexpr TGAColor blue = {255, 128, 64, 255};
constexpr TGAColor yellow = {0, 200, 255, 255};

void line(Vec2 start, Vec2 end, TGAImage &image, const TGAColor &color) {
    auto is_steep = false;

    if (std::abs(end.x - start.x) < std::abs(end.y - start.y)) {
        is_steep = true;
        std::swap(start.x, start.y);
        std::swap(end.x, end.y);
    }

    if (start.x > end.x) {
        std::swap(start, end);
    }

    for (auto x = start.x; x < end.x; x++) {
        const auto t = (x - start.x) / (end.x - start.x);
        const auto y = start.y + t * (end.y - start.y);

        if (is_steep) {
            image.set(static_cast<int>(y), static_cast<int>(x), color);
        } else {
            image.set(static_cast<int>(x), static_cast<int>(y), color);
        }
    }
}

int main(int argc, char **argv) {
    constexpr int width = 64;
    constexpr int height = 64;
    TGAImage framebuffer(width, height, TGAImage::RGB);

    const Vec2 A(7, 3);
    const Vec2 B(12, 37);
    const Vec2 C(62, 53);

    framebuffer.set(static_cast<int>(A.x), static_cast<int>(A.y), white);
    framebuffer.set(static_cast<int>(B.x), static_cast<int>(B.y), white);
    framebuffer.set(static_cast<int>(C.x), static_cast<int>(C.y), white);

    line(A, B, framebuffer, white);
    line(B, C, framebuffer, white);
    line(C, A, framebuffer, white);

    return framebuffer.write_tga_file("framebuffer.tga");
}
