#ifndef __APE_WINDOW_H__
#define __APE_WINDOW_H__

#include <SDL2/SDL_video.h> // For SDL_Window

#include "APE_Structure.h" // For Point and Size

namespace APE {
    /// @brief The Window static class, provides static methods to manage the APE window.
    class Window final {
    private:
        static SDL_Window* __window; // The SDL Window handler, null if not initialized.
    public:
        /// @brief Make the Window visible.
        static void Show();
        /// @brief Make the Window not visible.
        static void Hide();

        /// @brief Get the position of the Window.
        /// @return The position of the Window, or Point::Zero on failed.
        static Point GetPosition();
        /// @brief Set the position of the Window.
        /// @param Position The position to set.
        static void SetPosition(const Point& Position);

        /// @brief Get the size of the Window.
        /// @return The size of the Window, or Size::Zero on failed.
        static Size GetSize();
        /// @brief Set the size of the Window.
        /// @param Size The size to set, will not set if the given size area is 0.
        static void SetSize(const APE::Size& Size);

        /// @brief Check if the Window class is initialized.
        /// @return true if the Window class is initialized, false otherwise.
        static bool IsInitialized();
        /// @brief Initialize the Window class.
        /// @return true on success, false on failure.
        static bool Initialize();
        /// @brief Deinitialize the Window class.
        static void Deinitialize();
    };
}

#endif // __APE_WINDOW_H__