//
//  WSGameMenuScene.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-4-1.
//
//

#include "WSGameMenuScene.h"
bool
WSGameMenuScene::init()
{
    if (CCScene::init())
    {
        _backGroundLayer = new WSBackGroundLayer();
        _backGroundLayer->init();
        _backGroundLayer->setAnchorPoint(ccp(0, 0));
        _backGroundLayer->setPosition(ccp(0, 0));
        this->addChild(_backGroundLayer);
        _backGroundLayer->autorelease();
        
        return true;
    }
    return false;
}