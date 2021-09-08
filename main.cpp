#include "main.h"



int main()
{
    std::cout << "HELOOOOOOOOOOOO WORLD!!" << std::endl;
    
    
    
    
    GLchar *vertexSS, *fragmentSS;
    unsigned int vertexSSsize, fragmentSSsize;
    vertexSS = loadData("vertexS.vert", vertexSSsize);
    fragmentSS = loadData("fragmentS.frag", fragmentSSsize);
    
    
    
    GLFWwindow *window = windowInit("GRAVITYYYYYYYYYYY");
    
    GLuint VBO, VAO, program;
    openglInit(vertexSS, fragmentSS, VBO, VAO, program);
    
    cl_command_queue command_queue;
    cl_mem buffer;
    cl_kernel kernel;
    openclInit(command_queue, buffer, kernel);
    
    windowRender(window, VBO, VAO, program, command_queue, buffer, kernel);
    
    
    
    std::cout << "GOOOOODBYYYYYYE WORLD!!" << std::endl;
    return 0;
}
