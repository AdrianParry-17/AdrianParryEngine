#ifndef __APE_APPLICATION_H__
#define __APE_APPLICATION_H__

namespace APE {
    /// @brief The Application static class, use to managing the APE application.
    class Application final {
    private:
        static bool __is_running; // Use as flags to stop the application (true if running, false if stopped).
    public:
        /// @brief Check if the Application is currently running.
        /// @return true if the Application is currently running, false otherwise.
        static bool IsRunning();
        /// @brief Start the Application, will do nothing if already running.
        static void Start();
        /// @brief Stop the Application.
        static void Stop();
    };
}

#endif // __APE_APPLICATION_H__