//
//  SceneFactory.cpp
//  MastermindTest
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#include <stdio.h>
#include "SceneFactory.h"

//---------------------------------------------------------------------------------------------------------------------
// SceneFactory::instance
//---------------------------------------------------------------------------------------------------------------------
SceneFactory * SceneFactory::instance = nullptr;

//---------------------------------------------------------------------------------------------------------------------
// SceneFactory::create
//---------------------------------------------------------------------------------------------------------------------
MyScene * SceneFactory::create(int type)
{
    switch(type)
    {
        case GameState::MAIN_MENU:
        {
            return MainMenuScene::createScene();
        }
            
        case GameState::GAME_IN_PROGRESS:
        {
            return GameScene::createScene();
        }
            
        case GameState::HELP_MODE:
        {
            return HelpScene::createScene();
        }

        case GameState::GAME_ENDED:
        {
            return EndScene::createScene();
        }

        default:
            return NULL;
    }
}

//---------------------------------------------------------------------------------------------------------------------
// SceneFactory::SceneFactory
//---------------------------------------------------------------------------------------------------------------------
SceneFactory::SceneFactory()
{
    
}



