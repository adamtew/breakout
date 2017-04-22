#include "Game.hpp"

SpriteRenderer * Renderer;
GameObject *Player;

Game::Game(GLuint width, GLuint height)
  : State(GAME_ACTIVE), Width(width), Height(height)
{
  
}

Game::~Game()
{
  delete Renderer;
  delete Player;
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
    ResourceManager::LoadTexture("textures/family.jpg", GL_FALSE, "background");
    //ResourceManager::LoadTexture("textures/family.jpg", GL_TRUE, "face");
    ResourceManager::LoadTexture("textures/block.png", GL_FALSE, "block");
    ResourceManager::LoadTexture("textures/block_solid.png", GL_FALSE, "block_solid");
    ResourceManager::LoadTexture("textures/paddle.png", true, "paddle");
    // Load levels
    GameLevel one; one.Load("levels/1.lvl", this->Width, this->Height * 0.5);
    GameLevel two; two.Load("levels/2.lvl", this->Width, this->Height * 0.5);
    GameLevel three; three.Load("levels/3.lvl", this->Width, this->Height * 0.5);
    GameLevel four; four.Load("levels/4.lvl", this->Width, this->Height * 0.5);
    this->Levels.push_back(one);
    this->Levels.push_back(two);
    this->Levels.push_back(three);
    this->Levels.push_back(four);
    this->Level = 1;
    // load paddle
    glm::vec2 playerPos = glm::vec2(this->Width / 2 - PLAYER_SIZE.x / 2, this->Height - PLAYER_SIZE.y);
    Player = new GameObject(playerPos, PLAYER_SIZE, ResourceManager::GetTexture("paddle"));
}

void Game::ProcessInputs(GLfloat dt)
{
  if (this->State == GAME_ACTIVE)
  {
    GLfloat velocity = PLAYER_VELOCITY * dt;
    // Move playerboard
    if (this->Keys[GLFW_KEY_A])
    {
      if (Player->Position.x >= 0)
          Player->Position.x -= velocity;
    }
    if (this->Keys[GLFW_KEY_D])
    {
      if (Player->Position.x <= this->Width - Player->Size.x)
          Player->Position.x += velocity;
    }
  }
}

void Game::Update(GLfloat dt)
{
}

void Game::Render()
{
  if(this->State == GAME_ACTIVE)
  {
    // Draw background
    Texture2D texture = ResourceManager::GetTexture("background");
    Renderer->DrawSprite(texture, glm::vec2(0, 0), glm::vec2(this->Width, this->Height), 0.0f);
    // Draw level
    this->Levels[this->Level].Draw(*Renderer);
    // Draw player
    Player->Draw(*Renderer);  
  }
}

