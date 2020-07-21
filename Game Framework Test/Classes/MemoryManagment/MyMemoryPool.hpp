//
//  MyMemoryPool.hpp
//  CodePlayground
//
//  Created by Catalin Dinea on 7/30/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef MyMemoryPool_hpp
#define MyMemoryPool_hpp

#include <stdio.h>

class MyMemoryPool
{
    unsigned char** rawMemoryArray;     // This is where the whole memory pool is stored, in the form of a signly linked list
    unsigned char* head;                // Head of the memory array, points to the next free block
    unsigned int chunkSize;             // Size of a chunk of memory
    unsigned int numChunks;             // How many chunks we have in the array
    unsigned int rawMemoryArraySize;    // How many elements does the memory array have
    bool allowResize;                   // Is the memory pool allowed to grow in size?
    
public:
    // Constructor, destructor and helpers
    MyMemoryPool();
    ~MyMemoryPool();
    bool Init(unsigned int chunkSize, unsigned int numChunks);
    void Destroy();
    
    void* Allocate();
    void Free(void* toAllocate);
    
    unsigned int GetChunkSize();
    
    void SetAllowResize(bool toAllowResize);
    
private:
    // To reset all the internal variables
    void Reset();
    
    // Internal memory allocation helpers
    bool GrowMemoryArray();
    unsigned char* AllocateNewMemoryBlock();
    
    // Helpers for managing the linked list
    unsigned char * GetNext(unsigned char* block);
    void SetNext(unsigned char* blockToChange, unsigned char* newNext);
    
    // Don't allow copy constuctir
    MyMemoryPool(const MyMemoryPool& mem) { }
};

#endif /* MyMemoryPool_hpp */
