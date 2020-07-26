#ifndef RENDERER_H
#define RENDERER_H

/* ---- Ideas ----
 * Want flexibility in how rendering is setup and executed to allow for
 * new features to be added, and optimisations to be made, without breaking
 * any external code.
 * The Renderer should be completely responsible for the rendering pipeline.
 * ie: There shouldn't be any opengl calls in other classes.
 * Other classes (like Mesh, Shader, Material), should only store the information.
 * It is up to the renderer how to store the information in buffers and then
 * render it.
 * The Renderer needs to be able to access the original information, to check
 * if it has changed (use a dirty flag in the class), such as when matrices
 * update.
 * Therefore, a pointer/reference to the original data should be kept.
 * When rendering, if the dirty flag is set, any necessary recalculations are
 * made.
 * Entities/scenes should support hierarchical transforms. To decouple this
 * from the renderer, entities should be responsible for updating their
 * absolute transform.
 */

#include <map>
#include <list>

#include <glm/glm.hpp>

#include "data/shader.h"
#include "scene/camera.h"
#include "scene/light.h"
#include "data/material.h"
#include "data/mesh.h"
#include "scene/entity.h"
#include "data/resources.h"
#include "scene/scene.h"

namespace mist {


class Renderer {
public:
    Renderer() {}
    void render(const Scene &scene, const Resources &resources);
    void add_entity(const Entity& entity);
    void set_camera(Camera *camera){ this->camera = camera; }
    void set_light(Light *light){ this->light = light; }
private:
    std::list<const Entity&> entities;
    const Camera *camera;
    const Light *light;
};

} // namespace mist

#endif
