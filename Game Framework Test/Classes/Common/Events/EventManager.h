//
//  EventManager.h
//  MyGame
//
//  Created by Catalin Dinea on 9/17/19.
//

#ifndef EventManager_h
#define EventManager_h
#include <iostream>
#include <map>
#include "cocos2d.h"
#include "Observer.h"
#include "Config.h"
#include "IEventManager.h"
#include "IEventData.h"

class EventManager : public IEventManager
{
public:
    // Singleton
    static EventManager * getInstance()
    {
        if(instance == NULL)
            instance = new EventManager();
        
        return instance;
    }
    static EventManager * instance;
    
    ~EventManager();
    
    // Adds an observer for a specific event
    // @param EventType type     : specifies the type of the event
    // @param Observer * observer: Pointer to the that will be notified when the event is triggered
    virtual void addObserver(Observer*  observer, EventType type);
    
    // Removes an observer for a specific event
    // @param EventType type     : specifies the type of the event
    // @param Observer * observer: Pointer to the that will be removed from the eventype list
    virtual void removeObserver(Observer * observer, EventType type);
    
    // Calls all onNotify functions from all the Observers that are subscribed to a particular event
    // @param IEventDataPtr& eventData: Contains the EventType and Parameters that will be sent to the observers
    virtual void triggerEvent(const IEventDataPtr& eventData);
    
private:
    EventManager();
    
    // Keys are event types
    // Values are lists that contain all the observers that are subscribed to that EventType
    EventMap m_eventMap;
};

#endif /* EventManager_h */
