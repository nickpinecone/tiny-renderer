#pragma once

#include <string>
#include <vector>
#include <array>

#include "geometry.h"

class Model {
private:
    std::vector<Vec2> _vertices;
    std::vector<Vec3> _faces;

public:
    explicit Model(const std::string &filename);

    int len_vertices() const;

    int len_faces() const;

    Vec2 vertex_at(int index) const;

    Vec3 face_at(int index) const;
};
