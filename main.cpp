#include <cmath>
#include "tgaimage.h"
#include "geometry.h"
#include "model.h"

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
            image.set(std::round(y), std::round(x), color);
        } else {
            image.set(std::round(x), std::round(y), color);
        }
    }
}

int main(int argc, char **argv) {
    constexpr int width = 1000;
    constexpr int height = 1000;
    TGAImage framebuffer(width, height, TGAImage::RGB);

    Model model{"./obj/diablo3_pose/diablo3_pose.obj"};

    for (int i = 0; i < model.len_faces(); i++) {
        auto face = model.face_at(i);

        for (int j = 0; j < 3; j++) {
            auto start = model.vertex_at(face.at(j) - 1);
            auto end = model.vertex_at(face.at((j + 1) % 3) - 1);

            start.x = (start.x + 1) * width / 2.;
            start.y = (start.y + 1) * height / 2.;
            end.x = (end.x + 1) * width / 2.;
            end.y = (end.y + 1) * height / 2.;

            line(start, end, framebuffer, red);
        }
    }

    for (int i = 0; i < model.len_vertices(); i++) {
        auto vert = model.vertex_at(i);

        vert.x = (vert.x + 1) * width / 2.;
        vert.y = (vert.y + 1) * height / 2.;

        framebuffer.set(vert.x, vert.y, white);
    }

    return framebuffer.write_tga_file("framebuffer.tga");
}
