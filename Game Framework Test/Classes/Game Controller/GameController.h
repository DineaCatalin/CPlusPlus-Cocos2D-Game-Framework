//
//  GameController.h
//  MyGame
//
//  Created by Catalin Dinea on 9/30/19.
//

#ifndef GameController_h
#define GameController_h

#include <map>
#include "Config.h"
#include "GameStateHandler.h"
#include "GameStateHandlerFactory.h"

typedef std::map<GameState, GameStateHandler *> HandlerMap;

class GameController : public Observer
{
public:
    static GameController * create();
    
    void spawnMonster();
    virtual void onNotify(std::shared_ptr<IEventData> eventData);
        
private:
    GameController();
    ~GameController();
    
    bool init();
    void setActiveHandler(GameState state);
    
    HandlerMap * m_pHandlerMap;
    GameStateHandler  * m_pCurrentStateHandler;
};

#endif /* GameController_h */
