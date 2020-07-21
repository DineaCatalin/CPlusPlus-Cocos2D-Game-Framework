//
//  MyMemoryPool.cpp
//  CodePlayground
//
//  Created by Catalin Dinea on 7/30/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#include "MyMemoryPool.hpp"
#include <stdlib.h>
#include "iostream"

const static size_t CHUNK_HEADER_SIZE = sizeof(unsigned char *);

MyMemoryPool::MyMemoryPool()
{
    Reset();
}

MyMemoryPool::~MyMemoryPool()
{
    Destroy();
}

void MyMemoryPool::Destroy()
{
    for(int i = 0; i < rawMemoryArraySize; i++)
    {
        free(rawMemoryArray[i]);
    }
    
    free(rawMemoryArray);
}

void MyMemoryPool::Reset()
{
    chunkSize = 0;
    numChunks = 0;
    rawMemoryArraySize = 0;
    allowResize = true;
    rawMemoryArray = NULL;
    head = NULL;
}

unsigned char* MyMemoryPool::GetNext(unsigned char * block)
{
    unsigned char** fullChunk = (unsigned char**)block;
    return fullChunk[0]; //Pointer to next element in the array
}

void MyMemoryPool::SetNext(unsigned char* blockToChange, unsigned char* newNext)
{
    unsigned char** block = (unsigned char**)blockToChange;
    block[0] = newNext;
}

unsigned int MyMemoryPool::GetChunkSize()
{
    return chunkSize;
}

void MyMemoryPool::SetAllowResize(bool toAllowResize)
{
    allowResize = toAllowResize;
}

void MyMemoryPool::Free(void* blockToFree)
{
    // Check for blockToFree not to be NULL
    if(blockToFree)
    {
        unsigned char* chunkHeader = (unsigned char*)blockToFree - CHUNK_HEADER_SIZE;
        
        // Make the head point to this place
        SetNext(chunkHeader, head);
        head = chunkHeader;
    }
}

//void* MyMemoryPool::Allocate()
//{
//    // Find where head is pointing
//}

