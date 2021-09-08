#include "openclInitFunc.h"
#include <CL/cl.h>


void openclInit(
        cl_command_queue &command_queue, cl_mem &buffer, cl_kernel &kernel
                )
{
    unsigned int fileSize;
    char *kernelSource = loadData("myKernel.cl", fileSize);
    
    cl_int err = 0;
    cl_platform_id platform_id;
    cl_uint num_platforms;
    err = clGetPlatformIDs(1, &platform_id, &num_platforms);
    
    cl_device_id device_id;
    cl_uint num_devices;
    err = clGetDeviceIDs(
                platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &num_devices
                         );
    
    cl_context context;
    context = clCreateContext(nullptr, 1, &device_id, nullptr, nullptr, &err);
    
    command_queue = clCreateCommandQueue(context, device_id, 0, &err);
    
    buffer = clCreateBuffer(
                context, CL_MEM_READ_WRITE,
                c_objectArgsCount * g_objectsCount * sizeof(float), nullptr,
                &err
                );
    
    cl_program program;
    program = clCreateProgramWithSource(
                context, 1, const_cast<const char**>(&kernelSource),
                0, &err
                );
    
    err = clBuildProgram(program, 0, nullptr, nullptr, nullptr, nullptr);
    
    kernel = clCreateKernel(program, "mainn", &err);
    err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &buffer);
}
