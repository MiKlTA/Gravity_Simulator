#include "loadDataFunc.h"



char * loadData(const char *fileName, unsigned int &fileSize)
{
    std::ifstream ifs;
    ifs.open(fileName, std::ios::binary);
    if (!ifs.is_open()) return nullptr;
    
    ifs.seekg(0, std::ios::end);
    fileSize = ifs.tellg();
    ifs.seekg(0, std::ios::beg);
    if (fileSize == 0) return nullptr;
    
    fileSize++;
    char *data = new char[fileSize];
    ifs.read(data, fileSize - 1);
    data[fileSize - 1] = '\0';
    ifs.close();
    
    return data;
}
