#ifndef CALCONESTEP_H
#define CALCONESTEP_H



#include "commonLibraries.h"
#include "constants.h"
#include "globalVars.h"



void calcOneStep(
        std::queue<float *, std::list<float *>> *objects,
        cl_command_queue command_queue, cl_mem buffer, cl_kernel kernel
        );



#endif // CALCONESTEP_H
