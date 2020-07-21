//
//  IEventData.h
//  MyGame
//
//  Created by Catalin Dinea on 9/18/19.
//

#ifndef IEventData_h
#define IEventData_h
#include "Config.h"

typedef std::map<std::string, cocos2d::Ref *> ParameterMap;

// Interface for the data that is being sent as a parameter for an event
class IEventData
{
public:
    virtual EventType getType() = 0;                                    // Get the type of the event
    virtual void addParameter(std::string, cocos2d::Ref * param) = 0;   // Add parameters that will be sent
    virtual void setParameters(ParameterMap params) = 0;                // Set all parameters
    virtual cocos2d::Ref * getParameter(std::string paramName) = 0;     // Returns parameters
};

#endif /* IEventData_h */
