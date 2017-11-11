//
//  MemoryManager.cpp
//  memoryallocation
//
//  Created by Anderson, Sloan on 11/3/17.
//  Copyright © 2017 Anderson, Sloan. All rights reserved.
//

#include <stdio.h>
#include "MemoryManager.h"

MemoryBlock::MemoryBlock(int start, int newSize, bool nFree)
{
    startingAddr = start;
    size = newSize;
	free = nFree;
}


MemoryManager::MemoryManager()
{
    MemoryBlock init(0, INIT_MEMORY_POOL);
    init.free = true;
    
    mMemory.push_front(init);
    
    
}

MemoryManager::MemoryManager(int availableSpace)
{
	MemoryBlock init(0, availableSpace);
	init.free = true;

	mMemory.push_front(init);


}

MemoryManager::~MemoryManager(){}

int MemoryManager::allocateMemory(string processName, int size)
{
	MemoryBlock process(-1, size, false);
	process.Name = processName;


    for (auto it = mMemory.begin(); it != mMemory.end(); ++it)
    {
        if (it->free && it->size > size)
        {
			process.startingAddr = it->startingAddr;
			mMemory.insert(it, process);

			if (it->size != size)
			{
				it->startingAddr += process.size;
				it->size -= process.size;
			}
			else
				mMemory.erase(it);
			
            return size;
            
        }
    }
    return -1;
}

int MemoryManager::freeMemory(string proccessName)
{
    for (auto it = mMemory.begin(); it != mMemory.end(); ++it)
    {
        if (it->Name == proccessName)
        {
            it->Name = "";
            it->free = true;
            return it->size;
        }
    }
    return -1;
}
