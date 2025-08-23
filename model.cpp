#include "model.h"

#include <fstream>
#include <iostream>
#include <sstream>

Model::Model(const std::string &filename) {
    std::ifstream obj{filename};
    std::string line;

    while (std::getline(obj, line)) {
        std::string part;
        std::vector<double> values;

        if (line.starts_with("v ")) {
            std::stringstream stream(line.substr(2));
            while (std::getline(stream, part, ' ')) {
                auto value = std::stod(part);
                values.push_back(value);
            }

            _vertices.push_back(Vec2(values[0], values[1]));
        } else if (line.starts_with("f ")) {
            std::stringstream stream(line.substr(2));
            while (std::getline(stream, part, ' ')) {
                auto slash_index = part.find('/');
                part = part.substr(0, slash_index);
                auto value = std::stoi(part);
                values.push_back(value);
            }

            _faces.push_back(Vec3(values[0], values[1], values[2]));
        }
    }
}

int Model::len_vertices() const {
    return _vertices.size();
}

int Model::len_faces() const {
    return _faces.size();
}

Vec2 Model::vertex_at(int index) const {
    return _vertices[index];
}

Vec3 Model::face_at(int index) const {
    return _faces[index];
}
