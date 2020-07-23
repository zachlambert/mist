#ifndef MODEL_H
#define MODEL_h

#include <string>
#include <vector>

#include "mesh.h"

class Model {
public:
    Model(const std::vector<Mesh> meshes):meshes(meshes) {}
    void render(const Shader &shader)const;
private:
    std::vector<Mesh> meshes;
};

#endif
