# Gaviota Engine

The goal o this project is to build a 2D Game Engine in C++, using OpenGL. Currently, this build is not functional and the basic features are yet to be implemented. A further detailed roadmap is also being constructed, alongside an architecture documentation.

# Supported features

- Logger with simplified macros
- Cross platform build

# Next steps

- Event system
- Window system
- Basic math
- OpenGL core
- UI
- Renderer
- Shaders
- Camera
- Sprite handlers
- Phyisics system

# Build

First, clone this repository recursively

```bash
git clone --recurse-submodules git@github.com:MiguelRavagnani/Gaviota.git
```

As of now, the build is fully experimental. To do so, create a build file insite the repository directory:

```bash
mkdir build && cd build
```

And build the project

```bash
cmake .. && make -j4
```