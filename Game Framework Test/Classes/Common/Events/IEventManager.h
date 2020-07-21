//
//  IEventManager.h
//  MyGame
//
//  Created by Catalin Dinea on 9/17/19.
//

#ifndef IEventManager_h
#define IEventManager_h
#include "IEventData.h"
#include "Observer.h"


typedef std::shared_ptr<IEventData> IEventDataPtr;
typedef std::list<Observer *> ObserverList;
typedef std::map<int, ObserverList *> EventMap;
typedef std::shared_ptr<IEventData> IEventDataPtr;

// Interface class for the EventManager
class IEventManager{
    
public:
    virtual void addObserver(Observer * observer, EventType type) = 0;
    virtual void removeObserver(Observer * observer, EventType type) = 0;
    virtual void triggerEvent(const IEventDataPtr& eventData) = 0;
};

#endif /* IEventManager_h */
