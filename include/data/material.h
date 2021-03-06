#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <glm/glm.hpp>
#include "data/texture.h"

namespace mist {

enum class MaterialType {
    COLORED,
    TEXTURED
};

// Use pointers to textures, to allow for a null pointer
// when not using textures
struct Material {
    glm::vec3 diffuse_color;
    std::string diffuse_texture_path;
    unsigned int diffuse_texture_id;
    glm::vec3 specular_color;
    std::string specular_texture_path;
    unsigned int specular_texture_id;
    MaterialType type;
    std::size_t id;
    std::size_t shader_index;
};

} // namespace mist

#endif
