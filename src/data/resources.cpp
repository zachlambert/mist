#include "data/resources.h"
#include "create_model.h"
#include "load_model.h"
#include "create_material.h"

namespace mist {

bool Resources::create_model_from_file(const std::string &name, const std::string &relative_path)
{
    if (models.find(name) != models.end()) {
        Model model = load_model(base_dir + relative_path);
        models.insert(std::pair<std::string, Model>(name, model));
        return true;
    } else {
        return false;
    }
}

bool Resources::create_model_from_config(const std::string &name, const ModelConfig &config)
{
    if (models.find(name) != models.end()) {
        Model model = create_model(config);
        models.insert(std::pair<std::string, Model>(name, model));
        return true;
    } else {
        return false;
    }
}

bool Resources::create_material_from_config(const std::string &name, const MaterialConfig &config)
{
    if (materials.find(name) != materials.end()) {
        Material material = create_material(config);
        materials.insert(std::pair<std::string, Material>(name, material));
        return true;
    } else {
        return false;
    }
}

} // namespace mist
