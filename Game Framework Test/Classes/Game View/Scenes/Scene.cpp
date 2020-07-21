//
//  Scene.cpp
//  MyGame
//
//  Created by Catalin Dinea on 9/18/19.
//

#include <stdio.h>
#include "Scene.h"

//---------------------------------------------------------------------------------------------------------------------
// MyScene::init
//---------------------------------------------------------------------------------------------------------------------
bool MyScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    
    return true;
}

//---------------------------------------------------------------------------------------------------------------------
// MyScene::init
//---------------------------------------------------------------------------------------------------------------------
bool MyScene::initWithPhysics()
{
    if(!Scene::initWithPhysics())
    {
        return false;
    }
    
    return true;
}

//---------------------------------------------------------------------------------------------------------------------
// MyScene::render
//---------------------------------------------------------------------------------------------------------------------
void MyScene::render()
{
    cocos2d::Director::getInstance()->replaceScene(this);
}
