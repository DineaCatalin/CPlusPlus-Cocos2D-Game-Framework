//
//  GameStateWrapper.h
//  MyGame
//
//  Created by Catalin Dinea on 9/19/19.
//

#ifndef GameStateWrapper_h
#define GameStateWrapper_h
#include "Config.h"

// Wrapper for the GameState enum so that it can be sent as a Ref * parameter
class GameStateWrapper : public cocos2d::Ref{
public:
    GameStateWrapper(GameState state);
    GameState getState();
    void setState(GameState state);
    
private:
    GameState m_State;  
};

#endif /* GameStateWrapper_h */
