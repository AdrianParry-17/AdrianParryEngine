#ifndef __APE_WINDOW_H__
#define __APE_WINDOW_H__

#include <SDL2/SDL_video.h> // For SDL_Window

namespace APE {
    /// @brief The Window static class, provides static methods to manage the APE window.
    class Window final {
    private:
        static SDL_Window* __window; // The SDL Window handler, null if not initialized.
    public:
        /// @brief Initialize the Window class.
        /// @return true on success, false on failure.
        static bool Initialize();
        /// @brief Deinitialize the Window class.
        static void Deinitialize();
    };
}

#endif // __APE_WINDOW_H__