#ifndef _BALL_OBJECT_HPP_
#define _BALL_OBJECT_HPP_

#include <OpenGL/gl3.h>
#include <glm/glm.hpp>

#include "Game_Object.hpp"
#include "Texture.hpp"
#include "Sprite_Renderer.hpp"

class BallObject : public GameObject
{
  public:
    GLfloat Radius;
    GLboolean Stuck;

    BallObject();
    BallObject(glm::vec2 pos, GLfloat radius, glm::vec2 velocity, Texture2D sprite);

    glm::vec2 Move(GLfloat dt, GLuint window_width);
    void Reset(glm::vec2 position, glm::vec2 velocity);

};
#endif
