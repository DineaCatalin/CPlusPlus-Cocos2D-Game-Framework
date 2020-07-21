//
//  Subject.h
//  CodePlayground
//
//  Created by Catalin Dinea on 9/4/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef Subject_h
#define Subject_h

#include "Node.h"

class Subject{
public:
    void notifyObservers();
    void addObserver(Node * node);
    void removeObserver(Node * node);
    
private:
    Node * m_pHead;
};

#endif /* Subject_h */
