#ifndef _TEXTURE2D_HPP_
#define _TEXTURE2D_HPP_

//#include <GL/glew.h>
#include <OpenGL/gl3.h>

class Texture2D
{
  public:
  GLuint ID;
  GLuint Width, Height;

  GLint Internal_Format;
  GLint Image_Format;

  GLuint Wrap_S;
  GLuint Wrap_T;
  GLuint Filter_Min;
  GLuint Filter_Max;

  Texture2D();

  void Generate(GLuint width, GLuint height, unsigned char* data);

  void Bind() const;
};
#endif
