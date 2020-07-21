//
//  Scene.h
//  MastermindTest
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef Scene_h
#define Scene_h
#include "cocos2d.h"
#include "CommonMacros.h"
#include "GameStateWrapper.h"
#include "EventManager.h"
#include "EventData.h"
#include "Config.h"

// Wrapps the cocos2d::Scene and adds the render function which is called by the GameView when displaying a new scene
class MyScene : public cocos2d::Scene
{
public:
    // Theoretically this function should take care of rendering and pushing all the elements needed for rendering
    // to a DirectX or OpenGL API but as we are using cocos2d it only calls the Director to change the scene to this one
    virtual void render();
    
    // Calls the init from cocos2d::Scene
    virtual bool init();
    
    // Calls the initWithPhysics from cocos2d::Scene
    virtual bool initWithPhysics();
    
    // Will be called by the GameView once every N seconds
    // Named doUpdate to not interfere with the update from cocos2d::Scene
    virtual void doUpdate(float delta) = 0;
};

#endif /* Scene_h */
