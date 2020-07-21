//
//  Observer.h
//  MastermindTest
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef Observer_h
#define Observer_h
#include "IEventData.h"

// Interface for all objects that can be notified by the EventManager
class Observer
{
public:
    // Function that gets called when an observer object is being notified by the EventSystem
    virtual void onNotify(std::shared_ptr<IEventData> eventData) = 0;
};

#endif /* Observer_h */
