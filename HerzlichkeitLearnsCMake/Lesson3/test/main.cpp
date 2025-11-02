#include <adder.h>
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <arg1> <arg2>" << std::endl;
        return EXIT_FAILURE;
    }
    
    if (argv[1][0] >= 'a')
        std::cout << HZLCM::adder(argv[1][0], argv[2][0]) << std::endl;
    else
        std::cout << HZLCM::adder(argv[1][0] - '0', argv[2][0] - '0') << std::endl;
    
    return EXIT_SUCCESS;
}