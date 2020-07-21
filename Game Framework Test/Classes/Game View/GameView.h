//
//  GameView.h
//  MastermindTest
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef GameView_h
#define GameView_h
#include <iostream>
#include <map>
#include "Config.h"
#include "Observer.h"
#include "Scene.h"
#include "EventManager.h"
#include "SceneFactory.h"
#include "GameStateWrapper.h"
#include "GameController.h"

// GameView takes care of the visual representation of the Game by managing all the Scenes
class GameView : public Observer
{
public:
    // Returns a new GameView object, calling the constructor and init function
    static GameView * create();
    
    // Calls the render function of the active scene
    void render();
    
    // Method that will be called once every N seconds
    void update(float delta);
    
    // Returns the current scene
    MyScene * getCurrentScene();
    
    // This will be called by the EventManager
    virtual void onNotify(std::shared_ptr<IEventData> eventData);
    
private:
    GameView();
    ~GameView();
    
    // Populates the scene map with all the scenes in the game and adds the GameView as an observer for SCENE_CHANGED event
    bool init();
    
    // Change the current scene
    // @param GameState state: The scene will be changed to the Scene that corresponds to the GameState
    void setActiveScene(GameState state);
    
    // The current scene that is being displayed
    MyScene * m_pCurrentScene;
    
    GameController * m_pController;
    
};

#endif /* GameView_h */
