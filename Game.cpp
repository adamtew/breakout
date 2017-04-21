#include "Game.hpp"

SpriteRenderer * Renderer;

Game::Game(GLuint width, GLuint height)
  : State(GAME_ACTIVE), Width(width), Height(height)
{
  
}

Game::~Game()
{
  delete Renderer;
}

void Game::Init()
{
    // Load shaders
    ResourceManager::LoadShader("shaders/sprite.vert", "shaders/sprite.frag", nullptr, "sprite");
    // Configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width), static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // Load textures
    ResourceManager::LoadTexture("textures/family.jpg", GL_TRUE, "face");
    // Set render-specific controls
    Shader tempShader = ResourceManager::GetShader("sprite");
    Renderer = new SpriteRenderer(tempShader);
    //Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
}

void Game::ProcessInputs(GLfloat dt)
{
}

void Game::Update(GLfloat dt)
{
}

void Game::Render()
{
  Texture2D tempTexture = ResourceManager::GetTexture("face");
  Renderer->DrawSprite(tempTexture, glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}

