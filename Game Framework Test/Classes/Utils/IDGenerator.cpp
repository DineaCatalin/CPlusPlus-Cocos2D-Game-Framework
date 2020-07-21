//
//  IDGenerator.cpp
//  CodePlayground
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#include <stdio.h>
#include "IDGenerator.h"

int IDGenerator::m_currentID = 0;

int IDGenerator::getNextID()
{
    return ++m_currentID;
}
