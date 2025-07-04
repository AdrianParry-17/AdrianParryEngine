#include "APE/APE_Window.h"

SDL_Window* APE::Window::__window = nullptr; // Set to nullptr, meaning not initialized.

bool APE::Window::Initialize() {
    if (Window::__window)
        return true; // Already initialized, return true.

    // Create a new window.
    Window::__window = SDL_CreateWindow(
        "Game Window", // Set the title to "Game Window".
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // Set window position to center.
        800, 500, // Set the window size to 800x500.
        SDL_WINDOW_HIDDEN // Set the window flags to hidden (when created).
    );

    // Return true on success, or false on failure (SDL_CreateWindow return null).
    return (bool)Window::__window;
}

void APE::Window::Deinitialize() {
    if (!Window::__window)
        return; // Not initialized, return
    
    // Destroy the window.
    SDL_DestroyWindow(Window::__window);
}