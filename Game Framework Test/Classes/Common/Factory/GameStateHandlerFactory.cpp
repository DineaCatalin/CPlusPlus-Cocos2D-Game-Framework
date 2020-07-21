//
//  GameStateHandlerFactory.cpp
//  MyGame
//
//  Created by Catalin Dinea on 10/1/19.
//

#include <stdio.h>
#include "GameStateHandlerFactory.h"

GameStateHandlerFactory * GameStateHandlerFactory::instance = nullptr;

GameStateHandler * GameStateHandlerFactory::create(int type)
{
    switch(type)
    {
        case GameState::MAIN_MENU:
        {
            return new MainMenuStateHandler();
        }
            
        case GameState::GAME_IN_PROGRESS:
        {
            return new GameInProgressHandler();
        }
            
        case GameState::HELP_MODE:
        {
            return new HelpStateHandler();
        }

        case GameState::GAME_ENDED:
        {
            return new GameEndedStateHandlder();
        }

        default:
            return NULL;
    }
}

