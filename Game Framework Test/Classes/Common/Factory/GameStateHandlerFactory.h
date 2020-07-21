//
//  GameStateHandlerFactory.h
//  MyGame
//
//  Created by Catalin Dinea on 10/1/19.
//

#ifndef GameStateHandlerFactory_h
#define GameStateHandlerFactory_h

#include "AbstractFactory.h"
#include "MainMenuStateHandler.h"
#include "GameInProgressHandler.h"
#include "HelpStateHandler.h"
#include "GameEndedStateHandler.h"

class GameStateHandlerFactory : public AbstractHandlerFactory
{
public:
    // Singleton
    static GameStateHandlerFactory * getInstance()
    {
        if(instance == NULL)
            instance = new GameStateHandlerFactory();
        
        return instance;
    }
    
    virtual GameStateHandler * create (int type);
    
private:
    static GameStateHandlerFactory * instance;
};

#endif /* GameStateHandlerFactory_h */
