//
//  GameScene.cpp
//  MastermindTest
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#include <stdio.h>
#include "GameScene.h"

//---------------------------------------------------------------------------------------------------------------------
// GameScene::createScene
//---------------------------------------------------------------------------------------------------------------------
GameScene * GameScene::createScene()
{
    return GameScene::create();
}

//---------------------------------------------------------------------------------------------------------------------
// GameScene::init
//---------------------------------------------------------------------------------------------------------------------
bool GameScene::init()
{
    if(!MyScene::initWithPhysics())
        return false;
    
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    float y_last;
    float x_middle = origin.x + visibleSize.width/2;  // Middle x coordinate on the screen
    
    // Title label
    auto label = cocos2d::Label::createWithTTF("< You are playing the game. This is so much FUN! >", "fonts/Marker Felt.ttf", 25);
    y_last = origin.y + visibleSize.height - label->getContentSize().height;
    label->setPosition(cocos2d::Vec2(x_middle, y_last));
    this->addChild(label,1);
    
    // Exit button and label
    auto exitItem = cocos2d::MenuItemImage::create("res/btn_boost_stamina.png", "res/btn_boost_morale.png", CC_CALLBACK_0(GameScene::onExitButtonClicked, this));
    auto labelExit = cocos2d::Label::createWithTTF("< EXIT >", "fonts/Marker Felt.ttf", 20);
    y_last -= label->getContentSize().height * 1.5;
    exitItem->setPosition(cocos2d::Vec2(x_middle , y_last));
    labelExit->setPosition(cocos2d::Vec2(x_middle + label->getContentSize().width/2, y_last));
    exitItem->setContentSize(cocos2d::Size(30,30));
    this->addChild(labelExit,1);
    
    // Create the Menu
    auto menu = cocos2d::Menu::create(exitItem, NULL);
    menu->setPosition(cocos2d::Vec2::ZERO);
    this->addChild(menu,1);
    
    // Add a nice background
    auto background = cocos2d::Sprite::create("HelloWorld.png");
    background->setPosition(cocos2d::Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(background, 0);
    
    return true;
}

//---------------------------------------------------------------------------------------------------------------------
// GameScene::onExitButtonClicked
//---------------------------------------------------------------------------------------------------------------------
void GameScene::onExitButtonClicked()
{
    std::map<std::string, Ref *> params { { "SCENE", new GameStateWrapper(MAIN_MENU) } };
    std::shared_ptr<EventData> evtData(new EventData(SCENE_CHANGED, params));
    EventManager::getInstance()->triggerEvent(evtData);
}

//---------------------------------------------------------------------------------------------------------------------
// GameScene::doUpdate
//---------------------------------------------------------------------------------------------------------------------
void GameScene::doUpdate(float delta)
{
    for(auto &sceneObj : m_SceneObjects)
    {
        sceneObj.update(delta);
    }
}
