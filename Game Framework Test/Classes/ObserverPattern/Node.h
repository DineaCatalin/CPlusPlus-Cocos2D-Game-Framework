//
//  Node.h
//  CodePlayground
//
//  Created by Catalin Dinea on 9/4/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include "Observer.h"
#include "IDGenerator.h"

class Node{
public:
    Node(IObserver * obs);
    ~Node();
    
    // Getters and setters for the next Node
    void setNext(Node * next);
    Node * getNext();
    
    // Getters and setters for the Observer object
    void setObserver(IObserver * obs);
    IObserver * getObserver();
    
    int getID() { return m_id; }
    
    //Overload the == operator
    bool operator ==(Node& node);
    
private:
    int m_id;
    Node * m_pNext;
    IObserver * m_pObserver;
};

#endif /* Node_h */
