#include <adder.h>
#include <iostream>
#include <GLFW/glfw3.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <arg1> <arg2>" << std::endl;
        return EXIT_FAILURE;
    }
    
    if (argv[1][0] >= 'a')
        std::cout << tuto::add(argv[1][0], argv[2][0]) << std::endl;
    else
        std::cout << tuto::add(argv[1][0] - '0', argv[2][0] - '0') << std::endl;
    
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