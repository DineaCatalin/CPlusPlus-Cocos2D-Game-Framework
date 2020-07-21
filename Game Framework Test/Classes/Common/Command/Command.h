//
//  Command.h
//  MyGame
//
//  Created by Catalin Dinea on 10/11/19.
//

#ifndef Command_h
#define Command_h

class Command;
typedef std::shared_ptr<Command> StrongCommandPtr;
typedef std::weak_ptr<Command> WeakCommandPtr;

enum State
{
    UNINITIALIZED = 0,  // Created but not running
    REMOVED,            // Removed from the Command list but not destroyed; this can happen when a process that is already running is parented to another process.
    RUNNING,            // Command is executing
    PAUSED,             // the Command has been initialized but not running
    SUCCEEDED,          // The Command has executed with success and is now finished
    FAILED,             // The execution of the Command has failed
    ABORTED,            // Aborted or it may have not stated
};

class Command
{
    friend class CommandManager;
    
public:
    
    // Construct/Destruct
    Command();
    virtual ~Command();
    
    // End the process
    inline void succeed();
    inline void fail();
    
    // Pause the process
    inline void pause();
    inline void unpause();
    
    // Accessor
    State getState() { return m_State; }
    bool isAlive() { return m_State == RUNNING || m_State == PAUSED; }
    bool isPaused() { return m_State == PAUSED; }
    
    // Manage child command
    inline void attachChild(StrongCommandPtr pChild);
    StrongCommandPtr removeChild();
    StrongCommandPtr peekChild() { return m_pChild; }
    
protected:
    virtual void onInit() { m_State = RUNNING; }
    virtual void onUpdate(unsigned long deltaMs) = 0;
    virtual void onSuccess();
    virtual void onFail();
    virtual void onAbort();
    
private:
    void setState(State state) { m_State = state; }
    
    State m_State;                  // State of the Command
    StrongCommandPtr m_pChild;      // Child of the Command
};

#endif /* Command_h */
