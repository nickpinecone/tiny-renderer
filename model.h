#pragma once

#include <string>
#include <vector>
#include <array>

#include "geometry.h"

class Model {
private:
    std::vector<Vec2> _vertices;
    std::vector<std::array<int, 3>> _faces;

public:
    explicit Model(const std::string &filename);

    int len_vertices() const;

    int len_faces() const;

    Vec2 vertex_at(int index) const;

    std::array<int, 3> face_at(int index) const;
};
