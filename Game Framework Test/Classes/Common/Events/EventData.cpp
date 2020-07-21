//
//  EventData.cpp
//  MyGame
//
//  Created by Catalin Dinea on 9/18/19.
//

#include <stdio.h>
#include "EventData.h"

//---------------------------------------------------------------------------------------------------------------------
// EventData::EventData
//---------------------------------------------------------------------------------------------------------------------
EventData::EventData(EventType type)
{
    m_type = type;
}

//---------------------------------------------------------------------------------------------------------------------
// EventData::EventData
//---------------------------------------------------------------------------------------------------------------------
EventData::EventData(EventType type, ParameterMap params)
{
    m_type = type;
    m_parameters = params;
}

//---------------------------------------------------------------------------------------------------------------------
// EventData::~EventData
//---------------------------------------------------------------------------------------------------------------------
EventData::~EventData()
{
    
}

//---------------------------------------------------------------------------------------------------------------------
// EventData::getType
//---------------------------------------------------------------------------------------------------------------------
EventType EventData::getType()
{
    return m_type;
}

//---------------------------------------------------------------------------------------------------------------------
// EventData::setParameters
//---------------------------------------------------------------------------------------------------------------------
void EventData::setParameters(ParameterMap params)
{
    m_parameters = params;
}

//---------------------------------------------------------------------------------------------------------------------
// EventData::addParameter
//---------------------------------------------------------------------------------------------------------------------
void EventData::addParameter(std::string name, cocos2d::Ref * param)
{
    m_parameters.insert(std::make_pair(name, param));
}

//---------------------------------------------------------------------------------------------------------------------
// EventData::getParameter
//---------------------------------------------------------------------------------------------------------------------
cocos2d::Ref * EventData::getParameter(std::string name)
{
    return m_parameters.find(name)->second;
}

//---------------------------------------------------------------------------------------------------------------------
// EventData::getAllParameters
//---------------------------------------------------------------------------------------------------------------------
ParameterMap EventData::getAllParameters()
{
    return m_parameters;
}
