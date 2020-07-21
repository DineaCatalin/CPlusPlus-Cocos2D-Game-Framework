//
//  AbstractFactory.h
//  MastermindTest
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef AbstractFactory_h
#define AbstractFactory_h
#include "Scene.h"
#include "GameStateHandler.h"

// Interface for Scene Factory Objects
class AbstractSceneFactory
{
public:
    virtual MyScene * create(int type) = 0;
};

class AbstractHandlerFactory
{
public:
    virtual GameStateHandler * create (int type) = 0;
};

#endif /* AbstractFactory_h */
