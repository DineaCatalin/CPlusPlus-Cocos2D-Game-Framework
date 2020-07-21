//
//  CommandManager.h
//  MyGame
//
//  Created by Catalin Dinea on 10/11/19.
//

#ifndef CommandManager_h
#define CommandManager_h

#include "Command.h"

class CommandManager
{
    typedef std::list<StrongCommandPtr> CommandList;

public:
    ~CommandManager();
    
    unsigned int updateCommands(unsigned long deltaMs);
    void abortAllCommands(bool immediate);
    
    usigned int getProcessCount() { return m_commandList.size(); }
    
private:
    void clearAllCommands();
    
    CommandList m_commandList;
};

#endif /* CommandManager_h */
