#ifndef OBJECTSINITFUNC_H
#define OBJECTSINITFUNC_H



#include "../commonLibraries.h"
#include "../constants.h"
#include "../globalVars.h"



// float[][0] - x pos
// float[][1] - y pos
// float[][2] - x velocity
// float[][3] - y velocity
// float[][4] - mass
std::queue<float *, std::list<float *>> * objectsInit();



#endif // OBJECTSINITFUNC_H
