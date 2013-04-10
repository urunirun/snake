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
        
        _gameLayer = new WSGameLayer();
        _gameLayer->init();
        _gameLayer->setAnchorPoint(ccp(0, 0));
        _gameLayer->setPosition(ccp(0, 0));
        this->addChild(_gameLayer);
        _gameLayer->autorelease();
        
        CCSprite*   menuImage = CCSprite::create("menuLayer.png");
        menuImage->setAnchorPoint(ccp(0, 1));
        menuImage->setPosition(ccp(320, 520));
        this->addChild(menuImage);
        
    
        
        return true;
    }
    return false;
}