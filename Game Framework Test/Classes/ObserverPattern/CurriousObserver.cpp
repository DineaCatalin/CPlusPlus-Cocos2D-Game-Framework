//
//  CurriousObserver.cpp
//  CodePlayground
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#include <stdio.h>
#include "iostream"
#include "CurriousObserver.h"

void CurriousObserver::VOnNotify()
{
    std::cout << "I am observer observing something, what is it?" << std::endl;
}

CurriousObserver::CurriousObserver()
{
    
}

CurriousObserver::~CurriousObserver()
{
    
}


