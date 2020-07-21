//
//  MainMenuScene.h
//  MastermindTest
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef MainMenuScene_h
#define MainMenuScene_h

#include "Scene.h"
USING_NS_CC;

// Displays the main menu
class MainMenuScene : public MyScene
{
public:
    // We use this function to instantiate MainMenuScene objects
    static MainMenuScene * createScene();
    
    // Creates, positions and adds all the cocos2d visual elements
    virtual bool init();
    
    // Creates a MainMenuScene by calling the Constructor and the init() function
    CREATE_FUNC(MainMenuScene);
    
    // Called by GameView once every N seconds if this is the current Scene
    virtual void doUpdate(float delta);
    
private:
    // Called when the player presses the PLAY button, switches to the gane
    void onPlayButtonClicked();
    
    // Called when the player presses the HELP button, switches to the HELP menu
    void onHelpButtonClicked();
    
    // Called when the player presses the EXIT button, closes the game
    void onExitButtonClicked();
};

#endif /* MainMenuScene_h */
