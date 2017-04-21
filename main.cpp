

//#define GLEW_STATIC
//#include <GL/glew.h>
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

#include "Game.hpp"
#include "Resource_Manager.hpp"
#include <iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


const GLuint SCREEN_WIDTH = 800;

const GLuint SCREEN_HEIGHT = 600;

Game Breakout(SCREEN_WIDTH, SCREEN_HEIGHT);

int main(int argc, char* argv[])
{
  std::cout << "Hello World\n";
  if (!glfwInit())
  {
    std::cout << "GLFW Initialization failed\n";
    exit(1);
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout", NULL, NULL);
  if (window == NULL)
  {
    std::cout << "window construction failed " << __LINE__ << "\n";
    exit(1);
  }
  glfwMakeContextCurrent(window);

  //glewExperimental = GL_TRUE;
  //glewInit();
  glGetError();
  glfwSetKeyCallback(window, key_callback);

  glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
  glEnable(GL_CULL_FACE);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // Initialize game
  Breakout.Init();

  GLfloat deltaTime = 0.0f;
  GLfloat lastFrame = 0.0f;

  Breakout.State = GAME_ACTIVE;

  while (!glfwWindowShouldClose(window))
  {
    GLfloat currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    glfwPollEvents();

    Breakout.ProcessInputs(deltaTime);

    Breakout.Update(deltaTime);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    Breakout.Render();

    glfwSwapBuffers(window);
  }
  return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
  if (key >= 0 && key < 1024)
  {
    if (action == GLFW_PRESS)
      Breakout.Keys[key] = GL_TRUE;
    else if (action == GLFW_RELEASE)
      Breakout.Keys[key] = GL_FALSE;
  }
}
