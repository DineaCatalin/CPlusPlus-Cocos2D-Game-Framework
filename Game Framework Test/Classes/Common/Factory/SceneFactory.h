//
//  SceneFactory.h
//  MastermindTest
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef SceneFactory_h
#define SceneFactory_h
#include "AbstractFactory.h"
#include "MainMenuScene.h"
#include "HelpScene.h"
#include "GameScene.h"
#include "EndScene.h"
#include "Config.h"

class SceneFactory : public AbstractSceneFactory{
  
public:
    // Singleton
    static SceneFactory * getInstance()
    {
        if(instance == NULL)
            instance = new SceneFactory();
        
        return instance;
    }
    
    // Creates a specific scene based in the type specified as input
    virtual MyScene * create(int type);
    
private:
    static SceneFactory * instance;
    SceneFactory();
};

#endif /* SceneFactory_h */
