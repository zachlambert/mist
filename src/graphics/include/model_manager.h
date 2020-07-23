#ifndef MODEL_MANAGER_H
#define MODEL_MANAGER_H

#include <string>
#include <unordered_map>

#include "model.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class ModelManager {
public:
    ModelManager(const std::string &root_dir):root_dir(root_dir) {}
    const Model &get_model(const std::string &relative_path);
private:
    const std::string root_dir;
    std::unordered_map<std::string, Model> models;
};

#endif
