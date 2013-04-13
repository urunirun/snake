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
    if (WSGameScene::init())
    {
        _gameCore = new WSGameCore;
        _gameCore->initWithGameModeAndMapName(kShow, 0, this);
        
        _backGroundLayer = new WSBackGroundLayer();
        _backGroundLayer->init();
        _backGroundLayer->setAnchorPoint(ccp(0, 0));
        _backGroundLayer->setPosition(ccp(0, 0));
        this->addChild(_backGroundLayer);
        _backGroundLayer->autorelease();
        
        _gameLayer = new WSGameLayer();
        _gameLayer->initWithGameScene(this);
        _gameLayer->setAnchorPoint(ccp(0, 0));
        _gameLayer->setPosition(ccp(0, 0));
        this->addChild(_gameLayer);
        _gameLayer->autorelease();
        
        CCSprite*   menuImage = CCSprite::create("menuLayer.png");
        menuImage->setAnchorPoint(ccp(0, 1));
        menuImage->setPosition(ccp(320, 520));
        this->addChild(menuImage);
        
        CCJoystick* joyStick = new CCJoystick;
        joyStick->setScale(3);
        joyStick->init(10, 20, false, true, false, false);
        joyStick->setAnchorPoint(ccp(0, 0));
        joyStick->setPosition(ccp(160, 320));
        this->addChild(joyStick);
        joyStick->autorelease();
        joyStick->setBallTexture("joystick.png");
        joyStick->setDelegate(this);
        
        
        
        return true;
    }
    return false;
}


void
WSGameMenuScene::onCCJoyStickUpdate(CCNode* sender, float angle, CCPoint direction, float power)
{
    
}
