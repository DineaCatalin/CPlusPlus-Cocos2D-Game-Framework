//
//  GameView.cpp
//  MastermindTest
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#include <stdio.h>
#include "GameView.h"

//---------------------------------------------------------------------------------------------------------------------
// GameView::create
//---------------------------------------------------------------------------------------------------------------------
GameView * GameView::create()
{
    GameView * gView = new (std::nothrow) GameView();
    if(gView && gView->init())
    {
        return gView;
    }
    else
    {
        delete gView;
        gView = nullptr;
        return nullptr;
    }
}

//---------------------------------------------------------------------------------------------------------------------
// GameView::update
//---------------------------------------------------------------------------------------------------------------------
void GameView::update(float delta)
{
    m_pCurrentScene->doUpdate(delta);
}

//---------------------------------------------------------------------------------------------------------------------
// GameView::init
//---------------------------------------------------------------------------------------------------------------------
bool GameView::init()
{
    // Set the 1st scene as the main menu
    m_pCurrentScene = SceneFactory::getInstance()->create(MAIN_MENU);
    
    // Add this as an observer for the SCENE_CHANGED event
    EventManager::getInstance()->addObserver(this, SCENE_CHANGED);
    
    return true;
}

//---------------------------------------------------------------------------------------------------------------------
// GameView::GameView
//---------------------------------------------------------------------------------------------------------------------
GameView::GameView()
{
    // Initialize the Scene Map
    //m_sceneMap = new SceneMap();
}

//---------------------------------------------------------------------------------------------------------------------
// GameView::~GameView
//---------------------------------------------------------------------------------------------------------------------
GameView::~GameView()
{
    //delete m_sceneMap;
    m_pCurrentScene = nullptr;
}

//---------------------------------------------------------------------------------------------------------------------
// GameView::render
//---------------------------------------------------------------------------------------------------------------------
void GameView::render()
{
    m_pCurrentScene->render();
}

//---------------------------------------------------------------------------------------------------------------------
// GameView::onNotify
//---------------------------------------------------------------------------------------------------------------------
void GameView::onNotify(std::shared_ptr<IEventData> eventData)
{
    auto eventType = eventData->getType();
    
    switch(eventType)
    {
        case SCENE_CHANGED:
        {
            GameStateWrapper * state = (GameStateWrapper *)eventData->getParameter("SCENE");
            setActiveScene(state->getState());
            
            // Run the next Scene
            render();
            break;
        }
            
        default:
            return;
    }
}

//---------------------------------------------------------------------------------------------------------------------
// GameView::setActiveScene
//---------------------------------------------------------------------------------------------------------------------
void GameView::setActiveScene(GameState state)
{
    switch(state)
    {
        case GAME_IN_PROGRESS:
            m_pCurrentScene = SceneFactory::getInstance()->create(GAME_IN_PROGRESS);
            break;
        
        case MAIN_MENU:
            m_pCurrentScene = SceneFactory::getInstance()->create(MAIN_MENU);
            break;
            
        case GAME_ENDED:
            m_pCurrentScene = SceneFactory::getInstance()->create(GAME_ENDED);
            break;
            
        case HELP_MODE:
            m_pCurrentScene = SceneFactory::getInstance()->create(HELP_MODE);
            break;
            
        default:
            std::cout << "GameView::setActiveScene invalid game state." << std::endl;
            return;
    }
}

//---------------------------------------------------------------------------------------------------------------------
// GameView::getCurrentScene
//---------------------------------------------------------------------------------------------------------------------
MyScene * GameView::getCurrentScene()
{
    return m_pCurrentScene;
}
