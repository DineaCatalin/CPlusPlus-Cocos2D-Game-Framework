//
//  EventData.h
//  MyGame
//
//  Created by Catalin Dinea on 9/18/19.
//

#ifndef EventData_h
#define EventData_h
#include "Config.h"
#include <iostream>
#include <map>
#include "cocos2d.h"
#include "IEventData.h"

// Concrete implementation of IEventData
class EventData : public IEventData
{
public:
    EventData(EventType type);
    EventData(EventType type, ParameterMap params);
    ~EventData();
    
    EventType getType();                                            // Get the type of the event
    virtual void setParameters(ParameterMap params);                // Set all parameters
    virtual void addParameter(std::string name, cocos2d::Ref *);    // Add parameters that will be sent
    
    cocos2d::Ref * getParameter(std::string paramName);             // Returns a parameter with the name paramName
    ParameterMap getAllParameters();                                // Get all paramters
    
private:
    EventType m_type;                                               // EventType member
    ParameterMap m_parameters;                                      // A map for all the parameters with their name as key
};

#endif /* EventData_h */
