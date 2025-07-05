# The Game Engine name is APE, an alias for Adrian Game Engine.
cmake_minimum_required(VERSION 3.10)
project(APE VERSION 0.1.0 LANGUAGES CXX)

# Set the C++ standard to C++11.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(APE SHARED
    src/APE.cpp
    src/APE_Window.cpp
    src/APE_Structure.cpp
    src/APE_Application.cpp

    # Game Engine source code will be added here.
)

# Specify the include directories for the library.
target_include_directories(APE
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  # Used during build
        $<INSTALL_INTERFACE:include>                            # Used after installation
)

# Find the pkg-config tool, required to locate SDL2 and related libraries.
find_package(PkgConfig REQUIRED)

# Locate and link SDL2 with related modules

# - Find SDL2
pkg_check_modules(SDL2 REQUIRED sdl2)
target_include_directories(APE PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(APE PRIVATE ${SDL2_LIBRARIES})

# - Find SDL2_image (image loading library for SDL2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
target_include_directories(APE PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(APE PRIVATE ${SDL2_IMAGE_LIBRARIES})

# - Find SDL2_ttf (TrueType font rendering library for SDL2)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
target_include_directories(APE PRIVATE ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(APE PRIVATE ${SDL2_TTF_LIBRARIES})

# - Find SDL2_mixer (audio mixing library for SDL2)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)
target_include_directories(APE PRIVATE ${SDL2_MIXER_INCLUDE_DIRS})
target_link_libraries(APE PRIVATE ${SDL2_MIXER_LIBRARIES})

# - Find SDL2_gfx (graphics primitives for SDL2)
pkg_check_modules(SDL2_GFX REQUIRED SDL2_gfx)
target_include_directories(APE PRIVATE ${SDL2_GFX_INCLUDE_DIRS})
target_link_libraries(APE PRIVATE ${SDL2_GFX_LIBRARIES})


# Specify where to install the library.
install(TARGETS APE
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

# Install public header files.
install(DIRECTORY include/
    DESTINATION include
)

# Add example executable, use for testing.
add_executable(Game examples/Game.cpp)
target_link_libraries(Game PRIVATE APE)