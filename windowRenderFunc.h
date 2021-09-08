#ifndef WINDOWRENDERFUNC_H
#define WINDOWRENDERFUNC_H



#include "commonLibraries.h"
#include "globalVars.h"
#include "constants.h"

#include "calcTransformMatFunc.h"
#include "processInputFunc.h"
#include "objectsInitFunc.h"
#include "drawObjectsFunc.h"
#include "calcOneStepFunc.h"



void windowRender(
        GLFWwindow *window, GLuint VAO, GLuint VBO, GLuint program,
        cl_command_queue command_queue, cl_mem buffer, cl_kernel kernel
        );



#endif // WINDOWRENDERFUNC_H
