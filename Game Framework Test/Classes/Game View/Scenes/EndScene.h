//
//  EndScene.h
//  MastermindTest
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef EndScene_h
#define EndScene_h
#include "Scene.h"

// Screen 
class EndScene : public MyScene
{
public:
    // We use this function to instantiate MainMenuScene objects
    static EndScene * createScene();
    
    //
    virtual bool init();
    
    // Called by GameView once every N seconds if this is the current Scene
    virtual void doUpdate(float delta);
    
    // Creates a MainMenuScene by calling the Constructor and the init() function
    CREATE_FUNC(EndScene);
};

#endif /* EndScene_h */
