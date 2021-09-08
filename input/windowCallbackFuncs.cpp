#include "windowCallbackFuncs.h"



void errorCallback(int errCode, const char *errText)
{
    std::cout << errCode << ": " << errText << std::endl;
}

void windowSizeCallback(GLFWwindow *, int width, int height)
{
    glViewport(0, 0, width, height);
    g_viewportWidth = width;
    g_viewportHeight = height;
}

void keyCallback(GLFWwindow *window, int key, int, int action, int)
{
    if (key == GLFW_KEY_ESCAPE)
    {
        if (action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, true);
        }
    }
    else if (key == GLFW_KEY_A)
    {
        if (action == GLFW_PRESS)
        {
            g_goToLeft = true;
        }
        else if (action == GLFW_RELEASE)
        {
            g_goToLeft = false;
        }
    }
    else if (key == GLFW_KEY_D)
    {
        if (action == GLFW_PRESS)
        {
            g_goToRight = true;
        }
        else if (action == GLFW_RELEASE)
        {
            g_goToRight = false;
        }
    }
    else if (key == GLFW_KEY_W)
    {
        if (action == GLFW_PRESS)
        {
            g_goToUp = true;
        }
        else if (action == GLFW_RELEASE)
        {
            g_goToUp = false;
        }
    }
    else if (key == GLFW_KEY_S)
    {
        if (action == GLFW_PRESS)
        {
            g_goToDown = true;
        }
        else if (action == GLFW_RELEASE)
        {
            g_goToDown = false;
        }
    }
    else if (key == GLFW_KEY_Q)
    {
        if (action == GLFW_PRESS)
        {
            g_doIncrease = true;
        }
        else if (action == GLFW_RELEASE)
        {
            g_doIncrease = false;
        }
    }
    else if (key == GLFW_KEY_E)
    {
        if (action == GLFW_PRESS)
        {
            g_doDecrease = true;
        }
        else if (action == GLFW_RELEASE)
        {
            g_doDecrease = false;
        }
    }
}
