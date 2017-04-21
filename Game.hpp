#ifndef _GAME_HPP_
#define _GAME_HPP_

//#include <OpenGL/gl3.h>
//#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include "Shader.hpp"
#include "Resource_Manager.hpp"
#include "Sprite_Renderer.hpp"

enum GameState {
  GAME_ACTIVE,
  GAME_MENU,
  GAME_WIN
};

class Game
{
  public:
    GameState State;
    GLboolean Keys[1024];
    GLuint Width, Height;

    Game(GLuint width, GLuint height);
    ~Game();

    void Init();

    void ProcessInputs(GLfloat dt);
    void Update(GLfloat dt);
    void Render();

};
#endif
