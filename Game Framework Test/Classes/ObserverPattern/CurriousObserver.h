//
//  CurriousObserver.h
//  CodePlayground
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef CurriousObserver_h
#define CurriousObserver_h

#include "Observer.h"
#include "IDGenerator.h"

class CurriousObserver : public IObserver{
  
public:
    virtual void VOnNotify();
    CurriousObserver();
    ~CurriousObserver();
    
};

#endif /* CurriousObserver_h */
