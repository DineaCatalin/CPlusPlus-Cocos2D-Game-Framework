//
//  MainMenuStateHandler.h
//  MyGame
//
//  Created by Catalin Dinea on 10/1/19.
//

#ifndef MainMenuStateHandler_h
#define MainMenuStateHandler_h

class MainMenuStateHandler : public GameStateHandler
{
public:
    MainMenuStateHandler();
    ~MainMenuStateHandler();
    
    void startGame();
};

#endif /* MainMenuStateHandler_h */
