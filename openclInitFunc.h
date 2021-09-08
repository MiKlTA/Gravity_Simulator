#ifndef OPENCLINITFUNC_H
#define OPENCLINITFUNC_H



#include "commonLibraries.h"
#include "constants.h"
#include "globalVars.h"

#include "loadDataFunc.h"



void openclInit(
        cl_command_queue &command_queue, cl_mem &buffer, cl_kernel &kernel
                );



#endif // OPENCLINITFUNC_H
