#ifndef MESH_H
#define MESH_H

#include <string>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "shader.h"
#include "texture.h"

struct Vertex {
    glm::vec<3, GLfloat> position; // 3*4 = 12 bytes
    glm::vec<2, GLushort> tex_coords; // 2*2 = 4 bytes
    union {
        int normal_i32;
        struct {
            int nx:10;
            int ny:10;
            int nz:10;
            int nw:2;
        };
    };
    Vertex(glm::vec3 position, glm::vec2 tex_coords, glm::vec3 normal);
};


struct Material {
    const Texture &diffuse_texture;
    glm::vec3 diffuse_color;
    const Texture &specular_texture;
    glm::vec3 specular_color;
};

class Mesh {
public:
    Mesh(
        const std::vector<Vertex> &vertices,
        const std::vector<unsigned int> &indices,
        const Material &material);
    void render(const Shader &shader)const;
    // Raw mesh data
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    Material material;
private:
    // Render data
    unsigned int VAO, VBO, EBO;
};

#endif
