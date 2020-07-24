#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <string>
#include <unordered_map>

#include "data/texture.h"

namespace data {

class TextureManager {
public:
    TextureManager(const std::string &root_dir):root_dir(root_dir) {}
    const Texture &get_texture(const std::string &relative_path);
private:
    const std::string root_dir;
    std::unordered_map<std::string, Texture> textures;
};

} // namespace data

#endif
