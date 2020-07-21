//
//  MainMenuScene.cpp
//  MastermindTest
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#include <stdio.h>
#include "MainMenuScene.h"

//---------------------------------------------------------------------------------------------------------------------
// MainMenuScene::createScene
//---------------------------------------------------------------------------------------------------------------------
MainMenuScene * MainMenuScene::createScene()
{
    return MainMenuScene::create();
}

//---------------------------------------------------------------------------------------------------------------------
// MainMenuScene::init
//---------------------------------------------------------------------------------------------------------------------
bool MainMenuScene::init()
{
    if(!MyScene::initWithPhysics())
        return false;
    
    // Get screen coordinates so we can position elements
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    float x_middle = origin.x + visibleSize.width/2;  // Middle x coordinate on the screen
    float y_last;
    
    // Title label
    auto label = cocos2d::Label::createWithTTF("< Playground >", "fonts/Marker Felt.ttf", 25);
    y_last = origin.y + visibleSize.height - label->getContentSize().height;
    label->setPosition(Vec2(x_middle, y_last));
    this->addChild(label,1);
    
    // Play button and label
    auto playItem = MenuItemImage::create("res/btn_boost_shape.png", "res/btn_boost_morale.png", CC_CALLBACK_0(MainMenuScene::onPlayButtonClicked, this));
    auto labelPlay = cocos2d::Label::createWithTTF("< PLAY >", "fonts/Marker Felt.ttf", 20);
    y_last -= label->getContentSize().height * 3;
    playItem->setPosition(Vec2(x_middle - label->getContentSize().width/2, y_last));
    labelPlay->setPosition(Vec2(x_middle + label->getContentSize().width/2, y_last));
    this->addChild(labelPlay,1);
    
    // Help button and label
    auto helpItem = MenuItemImage::create("res/btn_boost_health.png", "res/btn_boost_morale.png", CC_CALLBACK_0(MainMenuScene::onHelpButtonClicked, this));
    auto labelHelp = cocos2d::Label::createWithTTF("< HELP >", "fonts/Marker Felt.ttf", 20);
    y_last -= label->getContentSize().height * 1.5;
    helpItem->setPosition(Vec2(x_middle - label->getContentSize().width/2, y_last));
    labelHelp->setPosition(Vec2(x_middle + label->getContentSize().width/2, y_last));
    this->addChild(labelHelp,1);
    
    // Exit button and label
    auto exitItem = MenuItemImage::create("res/btn_boost_stamina.png", "res/btn_boost_morale.png", CC_CALLBACK_0(MainMenuScene::onExitButtonClicked, this));
    auto labelExit = cocos2d::Label::createWithTTF("< EXIT >", "fonts/Marker Felt.ttf", 20);
    y_last -= label->getContentSize().height * 1.5;
    exitItem->setPosition(Vec2(x_middle - label->getContentSize().width/2, y_last));
    labelExit->setPosition(Vec2(x_middle + label->getContentSize().width/2, y_last));
    //this->addChild(exitItem,1);
    this->addChild(labelExit,1);
    
    // Create the Menu
    auto menu = Menu::create(playItem, helpItem, exitItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu,1);
    
    // Add a nice background
    auto background = Sprite::create("HelloWorld.png");
    background->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(background, 0);
    
    // TEST
    auto test = Sprite::create("res/bm_avatar.png");
    test->setPosition(Vec2(x_middle, y_last - 10));
    this->addChild(test);
    auto pb = PhysicsBody::createBox(Size(test->getContentSize().width, test->getContentSize().height));
    pb->setDynamic(true);
    test->setPhysicsBody(pb);
    
    std::cout << "Test physics body pos: " << test->getPhysicsBody()->getPosition().x << " , " << test->getPhysicsBody()->getPosition().y << std::endl;
    test->getPhysicsBody()->applyImpulse(Vec2(2,2));
    std::cout << "Test physics body pos: " << test->getPhysicsBody()->getPosition().x << " , " << test->getPhysicsBody()->getPosition().y << std::endl;
    //TEST
    
    return true;
}

//---------------------------------------------------------------------------------------------------------------------
// MainMenuScene::onPlayButtonClicked
//---------------------------------------------------------------------------------------------------------------------
void MainMenuScene::onPlayButtonClicked()
{
    GameStateWrapper * newScene = new GameStateWrapper(GAME_IN_PROGRESS);
    
    // Create map for params
    std::map<std::string, Ref*> params { {"SCENE",newScene} };
    
    std::shared_ptr<EventData> evtData(new EventData(SCENE_CHANGED, params));
    EventManager::getInstance()->triggerEvent(evtData);
}

//---------------------------------------------------------------------------------------------------------------------
// MainMenuScene::onHelpButtonClicked
//---------------------------------------------------------------------------------------------------------------------
void MainMenuScene::onHelpButtonClicked()
{
    
}

//---------------------------------------------------------------------------------------------------------------------
// MainMenuScene::onExitButtonClicked
//---------------------------------------------------------------------------------------------------------------------
void MainMenuScene::onExitButtonClicked()
{
    
}

//---------------------------------------------------------------------------------------------------------------------
// MainMenuScene::doUpdate
//---------------------------------------------------------------------------------------------------------------------
void MainMenuScene::doUpdate(float delta)
{
    
}
