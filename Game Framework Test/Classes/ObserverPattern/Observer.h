//
//  Observer.h
//  CodePlayground
//
//  Created by Catalin Dinea on 9/4/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef Observer_h
#define Observer_h

class IObserver{
public:
    virtual void VOnNotify() = 0;
};

#endif /* Observer_h */
