#ifndef _GAME_HPP_
#define _GAME_HPP_

//#include <OpenGL/gl3.h>
//#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <vector>
#include <tuple>

#include "Shader.hpp"
#include "Resource_Manager.hpp"
#include "Sprite_Renderer.hpp"
#include "Game_Level.hpp"
#include "Ball_Object.hpp"

enum GameState {
  GAME_ACTIVE,
  GAME_MENU,
  GAME_WIN
};

enum Direction {
  UP,
  RIGHT,
  DOWN,
  LEFT
};

typedef std::tuple<GLboolean, Direction, glm::vec2> Collision;

// player constants
const glm::vec2 PLAYER_SIZE(100, 20);
const GLfloat PLAYER_VELOCITY(500.0f);

// ball constants
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
const GLfloat BALL_RADIUS = 12.5f;

class Game
{
  public:
    GameState State;
    GLboolean Keys[1024];
    GLuint Width, Height;

    std::vector<GameLevel> Levels;
    GLuint Level;

    Game(GLuint width, GLuint height);
    ~Game();

    void Init();

    void ProcessInputs(GLfloat dt);
    void Update(GLfloat dt);
    void Render();
    void DoCollisions();

    void ResetLevel();
    void ResetPlayer();

};
#endif
