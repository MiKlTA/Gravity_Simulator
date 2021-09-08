#include "objectsInitFunc.h"



std::queue<float *, std::list<float *> > *objectsInit()
{
    std::queue<float *, std::list<float *>> *result
            = new std::queue<float *, std::list<float *>>();
    float *objects = new float[c_objectArgsCount * c_objectsCount];
    
    for (int i = 0; i < c_objectsCount; ++i)
    {
        objects[c_objectArgsCount * i + 0]
                = c_areaSize * (rand() / float(RAND_MAX) - 0.5f);
        
        objects[c_objectArgsCount * i + 1]
                = c_areaSize * (rand() / float(RAND_MAX) - 0.5f);
        
        objects[c_objectArgsCount * i + 2]
                = (2.0f * (rand() / float(RAND_MAX)) - 1.0f) * c_maxVelocity;
        objects[c_objectArgsCount * i + 3]
                = (2.0f * (rand() / float(RAND_MAX)) - 1.0f) * c_maxVelocity;
        
        objects[c_objectArgsCount * i + 4]
                = (c_maxMass - c_minMass)
                * (rand() / float(RAND_MAX)) + c_minMass;
    }
    
    result->push(objects);
    return result;
}
