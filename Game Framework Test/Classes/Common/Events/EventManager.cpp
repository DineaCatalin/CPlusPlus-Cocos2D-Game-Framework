//
//  EventManager.cpp
//  MyGame
//
//  Created by Catalin Dinea on 9/17/19.
//

#include <stdio.h>
#include "EventManager.h"


//---------------------------------------------------------------------------------------------------------------------
// EventManager::instance
//---------------------------------------------------------------------------------------------------------------------
EventManager * EventManager::instance = nullptr;

//---------------------------------------------------------------------------------------------------------------------
// EventManager::EventManager
//---------------------------------------------------------------------------------------------------------------------
EventManager::EventManager()
{
    for(int eventType = SCENE_CHANGED; eventType < EVENT_TYPE_COUNT; eventType++)
    {
        ObserverList * list = new ObserverList();
        auto pair = std::make_pair(eventType, list);
        m_eventMap.insert(pair);
    }
}

//---------------------------------------------------------------------------------------------------------------------
// EventManager::~EventManager
//---------------------------------------------------------------------------------------------------------------------
EventManager::~EventManager()
{
    
}

//---------------------------------------------------------------------------------------------------------------------
// EventManager::addObserver
//---------------------------------------------------------------------------------------------------------------------
void EventManager::addObserver(Observer * observer, EventType type)
{
    for(auto const& mapElement : m_eventMap)
    {
        if(mapElement.first == type)
        {
            mapElement.second->push_back(observer);
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------
// EventManager::removeObserver
//---------------------------------------------------------------------------------------------------------------------
void EventManager::removeObserver(Observer * observer, EventType type)
{
    EventMap::iterator it;
    for(it = m_eventMap.begin(); it != m_eventMap.end(); it++)
    {
        if(it->first == type)
        {
            m_eventMap.erase(it);
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------
// EventManager::triggerEvent
//---------------------------------------------------------------------------------------------------------------------
void EventManager::triggerEvent(const IEventDataPtr& eventData)
{
    for(auto const& mapElement : m_eventMap)
    {
        // Found the event type
        if(mapElement.first == eventData->getType())
        {
            ObserverList * observers = mapElement.second;
            ObserverList::iterator it;
            for(it = observers->begin(); it != observers->end(); it++)
            {
                (*it)->onNotify(eventData);
            }
        }
    }
}


