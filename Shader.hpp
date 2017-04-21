#ifndef _SHADER_HPP_
#define _SHADER_HPP_

#include <string>
//#include <OpenGL/gl3.h>
#define GLFW_INCLUDE_GLCOREARB
//#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
  public:
    GLuint ID;

    Shader() {}
    Shader &Use();

    void Compile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource = nullptr);
    
    // Utilities
    void SetFloat    (const GLchar* name, GLfloat value, GLboolean useShader = false);
    void SetInteger  (const GLchar* name, GLint value, GLboolean useShader = false);
    void SetVector2f (const GLchar* name, GLfloat x, GLfloat y, GLboolean useShader = false);
    void SetVector2f (const GLchar* name, const glm::vec2 &value, GLboolean useShader = false);
    void SetVector3f (const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader = false);
    void SetVector3f (const GLchar* name, const glm::vec3 &value, GLboolean useShader = false);
    void SetVector4f (const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader = false);
    void SetVector4f (const GLchar* name, const glm::vec4 &value, GLboolean useShader = false);
    void SetMatrix4  (const GLchar* name, const glm::mat4 &matrix, GLboolean useShader = false);
    
  private:
    void checkCompileErrors(GLuint object, std::string type);
};
#endif
