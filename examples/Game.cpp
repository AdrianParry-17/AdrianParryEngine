#include "APE/APE.h"

int main() {
    // Initialize the APE
    if (!APE::Initialize())
        return 1;

    // Run the application
    APE::Application::Start();

    // Deinitialize the APE.
    APE::Deinitialize();
    
    return 0;
}
