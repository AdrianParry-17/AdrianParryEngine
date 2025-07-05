#include "APE/APE_Window.h"

SDL_Window* APE::Window::__window = nullptr; // Set to nullptr, meaning not initialized.

void APE::Window::Show() {
    // Check if Window class is initialized
    if (Window::__window)
        SDL_ShowWindow(Window::__window);
}

void APE::Window::Hide() {
    // Check if Window class is initialized
    if (Window::__window)
        SDL_HideWindow(Window::__window);
}

APE::Point APE::Window::GetPosition() {
    if (!Window::__window)
        return Point::Zero; // Window is not initialized, return Point::Zero.
    
    // Query window position
    int res_x = 0, res_y = 0;
    SDL_GetWindowPosition(Window::__window, &res_x, &res_y);

    return Point(res_x, res_y);
}

void APE::Window::SetPosition(const APE::Point& Position) {
    if (!Window::__window)
        return; // Window is not initialized, return.

    // Adjust window position
    SDL_SetWindowPosition(Window::__window, Position.X, Position.Y);
}

APE::Size APE::Window::GetSize() {
    if (!Window::__window)
        return Size::Zero; // Window is not initialized, return Size::Zero.
    
    // Query window size
    int res_width = 0, res_height = 0;
    SDL_GetWindowSize(Window::__window, &res_width, &res_height);

    return Size(res_width, res_height);
}

void APE::Window::SetSize(const APE::Size& Size) {
    if (!Window::__window || Size.IsEmptyArea())
        return; // Window is not initialized, or the given size has empty area, return.

    // Adjust window size, use abs() to avoid negative size case.
    SDL_SetWindowSize(Window::__window, abs(Size.Width), abs(Size.Height));
}

bool APE::Window::IsInitialized() {
    return (bool)Window::__window;
}

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
    Window::__window = nullptr; // Set to null.
}