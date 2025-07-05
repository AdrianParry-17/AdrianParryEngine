#include "APE/APE.h"

int main() {
    // Initialize the APE
    if (!APE::Initialize())
        return 1;

    // Deinitialize the APE.
    APE::Deinitialize();
    
    return 0;
}
