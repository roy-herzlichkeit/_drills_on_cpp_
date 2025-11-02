#include <iostream>
#include <GLFW/glfw3.h>
#include <herzlich.h>

#ifdef USE_ADDER
    #include <adder.h>
#endif

int main(int argc, char** argv) {
    std::cout << argv[0] << " Version " << HERZLICH_MAJOR_VERSION << "." << HERZLICH_MINOR_VERSION << std::endl;

#ifdef USE_ADDER
    std::cout << "Adder library support: ENABLED" << std::endl;
#else
    std::cout << "Adder library support: DISABLED" << std::endl;
#endif

    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <arg1> <arg2>" << std::endl;
        return EXIT_FAILURE;
    }
    
#ifdef USE_ADDER
    if (argv[1][0] >= 'a')
        std::cout << tuto::add(argv[1][0], argv[2][0]) << std::endl;
    else
        std::cout << tuto::add(argv[1][0] - '0', argv[2][0] - '0') << std::endl;
#else
    // Fallback: simple addition without Adder library
    int a = (argv[1][0] >= 'a') ? argv[1][0] : (argv[1][0] - '0');
    int b = (argv[2][0] >= 'a') ? argv[2][0] : (argv[2][0] - '0');
    std::cout << (a + b) << std::endl;
#endif
    
    GLFWwindow* window;
    // int width, height;

    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    // glfwWindowHint(GLFW_DEPTH_BITS, 16);
    // glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    // Set callback functions
    // glfwSetFramebufferSizeCallback(window, reshape);
    // glfwSetKeyCallback(window, key);

    // glfwMakeContextCurrent(window);
    // gladLoadGL(glfwGetProcAddress);
    // glfwSwapInterval( 1 );

    // glfwGetFramebufferSize(window, &width, &height);
    // reshape(window, width, height);

    // // Parse command-line options
    // init();

    // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Draw gears
        // draw();

        // Update animation
        // animate();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    // Exit program
    exit( EXIT_SUCCESS );
}