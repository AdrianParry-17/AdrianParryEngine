#include "APE/APE.h"

#include <SDL2/SDL.h>

bool APE::Initialize() {
  // Initialize SDL2
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    return false;

  // On successful initialization, return true.
  return true;
}

void APE::Deinitialize() {
  SDL_Quit();
}
