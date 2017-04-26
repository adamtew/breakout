# Breakout

> This is a remake of the classic arcade game Breakout. Developed using C++ with OpenGL. Most of the code was found following [this](https://learnopengl.com/#!In-Practice/2D-Game/Breakout) tutorial.

### Build

The source code is not completely cross-platform, but it has been tested on macOS and Windows. To build from source enter the following:

```
git clone https://github.com/adamtew/breakout.git
cd breakout
make
```
this will generate the executable `breakout` in the current directory

### Dependencies

The program is fairly low-level and uses some static libraries to compile, but there are a couple dynamic libraries it depends on. When compiling from source, the following packages are required:

- [OpenGL](https://www.opengl.org/)
- [glm](http://glm.g-truc.net/0.9.8/index.html)
- [glfw3](http://www.glfw.org/)
- [GL/glcorearb.h](https://www.khronos.org/registry/OpenGL/api/GL/glcorearb.h)

