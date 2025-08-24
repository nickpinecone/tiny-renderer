#include <cmath>
#include "tgaimage.h"
#include "geometry.h"
#include "model.h"

constexpr TGAColor white = {255, 255, 255, 255}; // attention, BGRA order
constexpr TGAColor green = {0, 255, 0, 255};
constexpr TGAColor red = {0, 0, 255, 255};
constexpr TGAColor blue = {255, 128, 64, 255};
constexpr TGAColor yellow = {0, 200, 255, 255};

void pixel(double x, double y, TGAImage &image, const TGAColor &color) {
    image.set(static_cast<int>(std::round(x)), static_cast<int>(std::round(y)), color);
}

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
            pixel(y, x, image, color);
        } else {
            pixel(x, y, image, color);
        }
    }
}

Vec2 scale(Vec2 orig, int width, int height) {
    orig.x = (orig.x + 1) * width / 2.;
    orig.y = (orig.y + 1) * height / 2.;
    return orig;
}

int main(int argc, char **argv) {
    constexpr int width = 1000;
    constexpr int height = 1000;
    TGAImage framebuffer(width, height, TGAImage::RGB);

    Model model{"./obj/african_head/african_head.obj"};

    for (int i = 0; i < model.len_faces(); i++) {
        auto face = model.face_at(i);

        for (int j = 0; j < 3; j++) {
            auto start = model.vertex_at(face.at(j) - 1);
            auto end = model.vertex_at(face.at((j + 1) % 3) - 1);

            start = scale(start, width, height);
            end = scale(end, width, height);

            line(start, end, framebuffer, red);
        }
    }

    for (int i = 0; i < model.len_vertices(); i++) {
        auto vert = model.vertex_at(i);
        vert = scale(vert, width, height);

        pixel(vert.x, vert.y, framebuffer, white);
    }

    return framebuffer.write_tga_file("framebuffer.tga");
}
