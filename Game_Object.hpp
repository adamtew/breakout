#ifndef _GAME_OBJECT_HPP_
#define _GAME_OBJECT_HPP_

#include <OpenGL/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Texture.hpp"
#include "Sprite_Renderer.hpp"


class GameObject
{
  public:
    glm::vec2 Position, Size, Velocity;
    glm::vec3 Color;
    GLfloat Rotation;
    GLboolean IsSolid, Destroyed;

    Texture2D Sprite;
    GameObject();
    GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));

    virtual void Draw(SpriteRenderer& renderer);
};
#endif
