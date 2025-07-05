#include "APE/APE_Application.h"

#include "APE/APE_Window.h" // For Window class

#include <SDL2/SDL_events.h> // For SDL_Event

bool APE::Application::__is_running = false; // Set to false as default.

bool APE::Application::IsRunning() { return __is_running; }
void APE::Application::Stop() { __is_running = false; }
void APE::Application::Start() {
    if (__is_running)
        return;

    __is_running = true; // Set the running flag to true.
    SDL_Event event; // For handle event

    // Below is just an example running code, will change in the future

    Window::Show(); // Show the window
    while (__is_running) {
        // Handling all current event
        while (SDL_PollEvent(&event) != 0) {
            // Check the event type.
            switch (event.type)
            {
            case SDL_QUIT: // User request quit event. 
                Application::Stop(); // Stop the application.
                break;
            
            default:
                break;
            }
        }

        // Update + render code goes here.
        // But for now, it's empty.
    }

    Window::Hide(); // Hide the window.
}