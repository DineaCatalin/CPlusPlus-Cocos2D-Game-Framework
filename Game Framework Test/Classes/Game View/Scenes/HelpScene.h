//
//  HelpScene.h
//  MastermindTest
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef HelpScene_h
#define HelpScene_h
#include "Scene.h"

// Help Screen
class HelpScene : public MyScene{
  
public:
    // We use this function to instantiate HelpScene objects
    static HelpScene * createScene();
    
    //
    virtual bool init();
    
    // Called by GameView once every N seconds if this is the current Scene
    virtual void doUpdate(float delta);
    
    // Creates a HelpScene by calling the Constructor and the init() function
    CREATE_FUNC(HelpScene);
};

#endif /* HelpScene_h */
