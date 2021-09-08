#ifndef DRAWOBJECTSFUNC_H
#define DRAWOBJECTSFUNC_H



#include "../commonLibraries.h"
#include "../constants.h"
#include "../globalVars.h"

#include "../logic/calcTransformMatFunc.h"



void drawObjects(float *objects, GLuint transformLoc, GLuint colorLoc, 
                 GLuint objPosLoc, GLuint shiftLoc, GLuint projectionLoc);



#endif // DRAWOBJECTSFUNC_H
