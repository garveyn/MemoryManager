//
//  MemoryManager.h
//  memoryallocation
//
//  Created by Anderson, Sloan on 11/3/17.
//  Copyright © 2017 Anderson, Sloan. All rights reserved.
//

#ifndef MemoryManager_h
#define MemoryManager_h

#include <list>
#include <string>

const int INIT_MEMORY_POOL = 10000;

using namespace std;

struct MemoryBlock
{
    std::string Name;
    int startingAddr;
    int size;
    bool free;
    
    MemoryBlock(int start, int newSize, bool nFree = true);
    
};

class MemoryManager
{
private:
    list<MemoryBlock> mMemory;
    
public:
    MemoryManager();
	MemoryManager(int availableSpace);
    ~MemoryManager();
    
    int allocateMemory(string processName, int size);
    int freeMemory(string proccessName);
    
    
};


#endif /* MemoryManager_h */
