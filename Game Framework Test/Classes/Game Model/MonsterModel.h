//
//  MonsterModel.h
//  MyGame
//
//  Created by Catalin Dinea on 10/2/19.
//

#ifndef MonsterModel_h
#define MonsterModel_h

class MonsterModel
{
public:
    MonsterModel(cocos2d::Size size);
    ~MonsterModel();
    
    void moveByImpulse(cocos2d::Vec2 impulse);
    cocos2d::Vec2 getPosition();
private:
    cocos2d::PhysicsBody * m_pPhysicsBody;
};

#endif /* MonsterModel_h */
