#include <iostream>
#include "config.h"

#ifdef USE_USER_TOOLS
    #include "tools.h"
#endif

int main(int argc, char * argv[]) {
    std::cout << "Input Command Number : " << argc << std::endl;
    if (argc >= 1) {
        // report version
        std::cout << argv[0] << " Version " << CMakeTutorial_VERSION_MAJOR << "."
        << CMakeTutorial_VERSION_MINOR << std::endl;
    }
    if (argc >= 2) {
        const double inputValue = std::stod(argv[1]);
        std::cout << "Input Number : " << inputValue << std::endl;
    }

#ifdef USE_USER_TOOLS
    print_user("Test Lib Function !");
#endif
    return 0;
}