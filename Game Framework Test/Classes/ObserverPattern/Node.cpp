//
//  Node.cpp
//  CodePlayground
//
//  Created by Catalin Dinea on 9/4/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#include <stdio.h>
#include "Node.h"
#include "iostream"

Node::Node(IObserver * obs)
{
    m_id = IDGenerator::getNextID();
    m_pObserver = obs;
    m_pNext = NULL;
}

Node::~Node()
{
    m_id = NULL;
    m_pObserver = NULL;
    m_pNext = NULL;
}

IObserver * Node::getObserver()
{
    return m_pObserver;
}

void Node::setObserver(IObserver *obs)
{
    m_pObserver = obs;
    std::cout << "Node " << getID() << " setting observer" << std::endl;
}

Node * Node::getNext()
{
    return m_pNext;
}

void Node::setNext(Node *next)
{
    m_pNext = next;
}

bool Node::operator==(Node& node)
{
    if(this->getID() == node.getID())
        return true;
    
    return false;
}
