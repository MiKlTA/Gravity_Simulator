#include "windowInitFunc.h"



GLFWwindow * windowInit(const char *title)
{
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWmonitor *primaryMonitor = glfwGetPrimaryMonitor();
    int width, height;
    glfwGetMonitorWorkarea(primaryMonitor, nullptr, nullptr, &width, &height);
    
    GLFWwindow *window = glfwCreateWindow(
//                width, height, title, primaryMonitor, 0
                width, height, title, nullptr, 0
                                          );
    glfwSetErrorCallback(errorCallback);
    glfwSetWindowSizeCallback(window, windowSizeCallback);
    glfwSetKeyCallback(window, keyCallback);
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    
    windowSizeCallback(window, width, height);
    
    return window;
}
