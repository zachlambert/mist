#include "scene/entity.h"
#include <iostream>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

namespace mist {

void Entity::set_scale(float uniform_scale_factor)
{
    model_scaling = glm::scale(glm::vec3(
        uniform_scale_factor, uniform_scale_factor, uniform_scale_factor
    ));
}
void Entity::set_scale(const glm::vec3 &scale_factors)
{
    model_scaling = glm::scale(scale_factors);
}

void Entity::set_orientation(const glm::mat4 &orientation)
{
    model_rotation = orientation;
}

void Entity::set_position(const glm::vec3 &vector)
{
    model_translation = glm::translate(vector);
}

} // namespace mist
