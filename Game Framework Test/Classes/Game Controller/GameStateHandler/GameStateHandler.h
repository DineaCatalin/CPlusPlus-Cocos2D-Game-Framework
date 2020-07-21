//
//  GameStateHandler.h
//  MyGame
//
//  Created by Catalin Dinea on 10/1/19.
//

#ifndef GameStateHandler_h
#define GameStateHandler_h

class GameStateHandler
{
public:
    //virtual void handle() = 0;
    virtual void spawnPlayer();
    virtual void spawnMonster();
    
};

#endif /* GameStateHandler_h */
