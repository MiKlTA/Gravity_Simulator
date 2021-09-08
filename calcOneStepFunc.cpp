#include "calcOneStepFunc.h"



void calcOneStep(
        std::queue<float *, std::list<float *>> *objects,
        cl_command_queue command_queue, cl_mem buffer, cl_kernel kernel
        )
{
    float *oldestStep = objects->back();
    
    cl_int err;
    
    err = clEnqueueWriteBuffer(
                command_queue, buffer, CL_TRUE,
                0, c_objectArgsCount * c_objectsCount * sizeof(float),
                oldestStep,
                0, nullptr, nullptr
                );
    
    const unsigned int workGroupSize[] = {c_objectsCount, c_objectsCount};
    err = clEnqueueNDRangeKernel(
                command_queue, kernel,
                2, nullptr, workGroupSize, nullptr,
                0, nullptr, nullptr
                );
    
    float *newStep = new float[c_objectArgsCount * c_objectsCount];
    err = clEnqueueReadBuffer(
                command_queue, buffer, CL_TRUE,
                0, c_objectArgsCount * c_objectsCount * sizeof(float), newStep,
                0, nullptr, nullptr
                );
    objects->push(newStep);
}
