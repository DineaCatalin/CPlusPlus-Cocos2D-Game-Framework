//
//  GameInProgressHandler.h
//  MyGame
//
//  Created by Catalin Dinea on 10/1/19.
//

#ifndef GameInProgressHandler_h
#define GameInProgressHandler_h

#include "GameStateHandler.h"

class GameInProgressHandler : public GameStateHandler
{
public:
    GameInProgressHandler();
    ~GameInProgressHandler();
    
    void addMonster();
    void moveMonsterByImpulse(cocos2d::Vec2 impulse);
    virtual void spawnPlayer();
};

#endif /* GameInProgressHandler_h */
