cmake_minimum_required(VERSION 4.0)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.4)

FetchContent_Declare(
  glad
  GIT_REPOSITORY https://github.com/Dav1dde/glad.git
  GIT_TAG v2.0.8)

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 1.0.3)

project(Multipong LANGUAGES CXX C)
add_executable(Multipong)


FetchContent_GetProperties(glad)
if(NOT glad_POPULATED)
message("Fetching glad")
FetchContent_MakeAvailable(glad)

add_subdirectory("${glad_SOURCE_DIR}/cmake" glad_cmake)
glad_add_library(
  glad
    REPRODUCIBLE
    EXCLUDE_FROM_ALL
    LOADER
    API
    gl:core=4.6
    EXTENSIONS
    GL_ARB_bindless_texture
    GL_EXT_texture_compression_s3tc)
endif()

FetchContent_MakeAvailable(glfw glm)

target_sources(Multipong PRIVATE src/main.cpp)

target_include_directories(Multipong PRIVATE header)

find_package(OpenGL REQUIRED)

target_link_libraries(Multipong PRIVATE OpenGL::GL glfw glad glm)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
