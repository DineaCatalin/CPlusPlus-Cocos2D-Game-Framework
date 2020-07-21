//
//  CommandManager.cpp
//  MyGame
//
//  Created by Catalin Dinea on 10/11/19.
//

#include <stdio.h>
#include "Command.h"
#include "CommandManager.h"

unsigned int CommandManager::updateCommands(unsigned long deltaMs)
{
    int succededCommands = 0;
    int failedCommands = 0;
    
    auto it = m_commandList.begin();
    
    while(it != m_commandList.end())
    {
        StrongCommandPtr commandPtr = *it;
        auto thisIt = it;
        ++it;
        
        auto state = commandPtr->getState();
        
        if(state == State::UNINITIALIZED)
        {
            commandPtr->onInit();
        }
                
    }
    
}


