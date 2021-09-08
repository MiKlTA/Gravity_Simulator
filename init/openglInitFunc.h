#ifndef OPENGLINITFUNC_H
#define OPENGLINITFUNC_H



#include "../commonLibraries.h"



void openglInit(
        const char *vertexSS, const char *fragmentSS,
        GLuint &VBO, GLuint &VAO, GLuint &program
        );



#endif // OPENGLINITFUNC_H
