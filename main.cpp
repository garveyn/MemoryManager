//
//  main.cpp
//  memoryallocation
//
//  Created by Anderson, Sloan on 11/3/17.
//  Copyright © 2017 Anderson, Sloan. All rights reserved.
//

#include <iostream>
#include "MemoryManager.h"

using namespace std;

int main()
{
    MemoryManager mM(1000);
    
	cout << mM.allocateMemory("Edge", 1000) << endl;
	cout << mM.allocateMemory("Steam", 2000) << endl;
	cout << mM.freeMemory("Edge") << endl;
	cout << mM.allocateMemory("Chrome", 500) << endl;
    
    cin.get();
    
    return 0;
}
