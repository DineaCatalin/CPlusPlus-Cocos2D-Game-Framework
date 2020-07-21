//
//  Subject.cpp
//  CodePlayground
//
//  Created by Catalin Dinea on 9/4/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#include <stdio.h>
#include "Subject.h"
#include "iostream"

void Subject::notifyObservers(){
    
    Node * currentNode;
    
    // Check if we actually have Observers
    if(m_pHead != NULL)
    {
        currentNode = m_pHead;
    }
    else
    {
        std::cout << "Subject has no observers" << std::endl;
        return;
    }
    
    while(currentNode != NULL)
    {
        currentNode->getObserver()->VOnNotify();
        currentNode = currentNode->getNext();
    }
}

void Subject::addObserver(Node *node)
{
    std::cout << "Subject is adding Node " << node->getID() << std::endl;
    
    // Subject has no Observers
    if(m_pHead == NULL)
    {
        m_pHead = node;
        return;
    }
    
    // Subject has no Observers
    if(m_pHead->getNext() == NULL)
    {
        m_pHead->setNext(node);
        return;
    }
    
    Node * temp = m_pHead->getNext();
    m_pHead->setNext(node);
    node->setNext(temp);
}

void Subject::removeObserver(Node * node)
{
    Node * currentNode = m_pHead;
    
    while(currentNode != NULL)
    {
        if(currentNode->getNext() == node)
        {
            Node * tmp = currentNode->getNext();
            currentNode->setNext(currentNode->getNext()->getNext());
            tmp->setNext(NULL);
            std::cout << "Subject is removing Node " << node->getID() << std::endl;
            return;
        }
        
        currentNode = currentNode->getNext();
    }
}
