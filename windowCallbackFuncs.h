#ifndef WINDOWCALLBACKFUNCS_H
#define WINDOWCALLBACKFUNCS_H



#include "commonLibraries.h"
#include "globalVars.h"



void errorCallback(int errCode, const char *errText);
void windowSizeCallback(GLFWwindow *, int width, int height);
void keyCallback(GLFWwindow *window, int key, int, int action, int);



#endif // WINDOWCALLBACKFUNCS_H
