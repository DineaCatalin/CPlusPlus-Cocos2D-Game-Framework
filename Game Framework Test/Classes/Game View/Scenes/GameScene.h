//
//  GameScene.h
//  MastermindTest
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef GameScene_h
#define GameScene_h
#include "Scene.h"
#include "ObjectView.h"

// Scene where the gameplay happens
class GameScene : public MyScene
{
public:
    // We use this function to instantiate GameScene objects
    static GameScene * createScene();
    
    //
    virtual bool init();
    
    // Called by GameView once every N seconds if this is the current Scene
    virtual void doUpdate(float delta);

    // Creates a MainMenuScene by calling the Constructor and the init() function
    CREATE_FUNC(GameScene);
private:
    
    //
    void onExitButtonClicked();
    
    std::vector<ObjectView> m_SceneObjects;
};

#endif /* GameScene_h */
