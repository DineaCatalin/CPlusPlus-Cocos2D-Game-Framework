//
//  Config.h
//  MastermindTest
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef Config_h
#define Config_h

// Configuration file - contains common enums and settings for the game

// Flag for debugging
#define DEBUG true

// Represents the state of the game
enum GameState
{
    MAIN_MENU = 0,
    GAME_IN_PROGRESS,
    GAME_ENDED,
    HELP_MODE,
};

// Represents the type of event that can be triggered by the EventManager
enum EventType
{
    SCENE_CHANGED,
    EVENT_TYPE_COUNT     // Used only for determining the end of the enum
};



#endif /* Config_h */
