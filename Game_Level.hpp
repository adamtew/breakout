#ifndef _GAME_LEVEL_HPP_
#define _GAME_LEVEL_HPP_

#include <OpenGL/gl3.h>
#include <vector>

#include "Sprite_Renderer.hpp"
#include "Game_Object.hpp"

class GameLevel
{
  public:
    std::vector<GameObject> Bricks;

    GameLevel() {};

    void Load(const GLchar* file, GLuint levelWidth, GLuint levelHeight);

    void Draw(SpriteRenderer& renderer);

    GLboolean IsCompleted();

  private:
    void init(std::vector<std::vector<GLuint> > tileData, GLuint levelWidth, GLuint levelHeight);
};
#endif
