//
//  MonsterModel.cpp
//  MyGame
//
//  Created by Catalin Dinea on 10/2/19.
//

#include <stdio.h>
#include "MonsterModel.h"

MonsterModel::MonsterModel(cocos2d::Size size)
{
    m_pPhysicsBody = cocos2d::PhysicsBody::createBox(size);
}

cocos2d::Vec2 MonsterModel::getPosition()
{
    return m_pPhysicsBody->getPosition();
}

void MonsterModel::moveByImpulse(cocos2d::Vec2 impulse)
{
    m_pPhysicsBody->applyImpulse(impulse);
}
