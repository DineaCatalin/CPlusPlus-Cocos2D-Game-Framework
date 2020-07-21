//
//  GameController.cpp
//  MyGame
//
//  Created by Catalin Dinea on 9/30/19.
//

#include <stdio.h>
#include "GameController.h"

GameController::GameController()
{
    m_pHandlerMap = new HandlerMap();
}

GameController * GameController::create()
{
    GameController * gController = new GameController();
    if(gController && gController->init())
    {
        return gController;
    }
    else
    {
        delete gController;
        gController = nullptr;
        return nullptr;
    }
}

bool GameController::init()
{
    auto factory = GameStateHandlerFactory::getInstance();
    
    GameStateHandler * gameInProgressHandler = factory->create(GAME_IN_PROGRESS);
    GameStateHandler * mainMenuHandler       = factory->create(MAIN_MENU);
    GameStateHandler * helpMenuHandler       = factory->create(HELP_MODE);
    GameStateHandler * gameEndHandler        = factory->create(GAME_ENDED);
    
    m_pHandlerMap->insert(std::make_pair(GAME_IN_PROGRESS, gameInProgressHandler));
    m_pHandlerMap->insert(std::make_pair(MAIN_MENU, mainMenuHandler));
    m_pHandlerMap->insert(std::make_pair(HELP_MODE, helpMenuHandler));
    m_pHandlerMap->insert(std::make_pair(GAME_ENDED, gameEndHandler));
    
    // Add this as an observer for the SCENE_CHANGED event
    EventManager::getInstance()->addObserver(this, SCENE_CHANGED);

    m_pCurrentStateHandler = mainMenuHandler;
    
    return true;
}

void GameController::onNotify(std::shared_ptr<IEventData> eventData)
{
    auto eventType = eventData->getType();
    
    switch(eventType)
    {
        case SCENE_CHANGED:
        {
            GameStateWrapper * state = (GameStateWrapper *)eventData->getParameter("SCENE");
            setActiveHandler(state->getState());
            break;
        }
        
        default:
            return;
    }

}

void GameController::setActiveHandler(GameState state)
{
    switch(state)
    {
        case GAME_IN_PROGRESS:
            m_pCurrentStateHandler = m_pHandlerMap->at(GAME_IN_PROGRESS);
            break;
        
        case MAIN_MENU:
            m_pCurrentStateHandler = m_pHandlerMap->at(MAIN_MENU);
            break;
            
        case GAME_ENDED:
            m_pCurrentStateHandler = m_pHandlerMap->at(GAME_ENDED);
            break;
            
        case HELP_MODE:
            m_pCurrentStateHandler = m_pHandlerMap->at(HELP_MODE);
            break;
            
        default:
            std::cout << "GameController::setActiveHandler invalid game state." << std::endl;
            return;
    }
}

void GameController::spawnMonster()
{
    if(m_pCurrentStateHandler != m_pHandlerMap->at(GAME_IN_PROGRESS))
    {
        m_pCurrentStateHandler->spawnMonster();
    }
}
