#include "initialReadSimParamsFunc.h"



void initialReadSimParams()
{
    std::string input;
    
    std::cout << "Please, write initial simulation's parameters.\n"
              << "If you want to keep the default value press 'enter'.\n"
              << std::endl;
    
    std::cout << "Objects count (500): " << std::endl;
    std::cin >> input;
    g_objectsCount = input.empty() ? 500 : std::atoi(input.c_str());
    
    std::cout << "Area size (10.0): " << std::endl;
    std::cin >> input;
    g_areaSize = input.empty() ? 10.0f : std::atof(input.c_str());
    
    std::cout << "Max velocity x0.000001/micro- (10.0): " << std::endl;
    std::cin >> input;
    g_maxVelocity = input.empty() ? 10.0f : std::atof(input.c_str());
    g_maxVelocity *= 0.000001f;
    
    std::cout << "Min mass x0.000001/micro- (10.0): " << std::endl;
    std::cin >> input;
    g_minMass = input.empty() ? 10.0f : std::atof(input.c_str());
    g_minMass *= 0.000001f;
    
    std::cout << "Max mass x0.000001/micro- (100.0): " << std::endl;
    std::cin >> input;
    g_maxMass = input.empty() ? 100.0f : std::atof(input.c_str());
    g_maxMass *= 0.000001f;
}
