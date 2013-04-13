//
//  WSGameScene.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-13.
//
//

#include "WSGameScene.h"

void
WSGameScene::drawScene()
{
}

void
WSGameScene::drawTimeLabel()
{
    
}

WSGameCore*
WSGameScene::getGameCore()
{
    return _gameCore;
}

bool
WSGameScene::initWithGameCoreMode(WSGameMode mode)
{
    if (CCScene::init())
    {
        _gameCore = new WSGameCore;
        _gameCore->initWithGameModeAndMapName(mode, 0, this);
        
        _backGroundLayer = new WSBackGroundLayer();
        _backGroundLayer->init();
        _backGroundLayer->setAnchorPoint(ccp(0, 0));
        _backGroundLayer->setPosition(ccp(0, 0));
        this->addChild(_backGroundLayer);
        _backGroundLayer->autorelease();
        
        _gameBackGroundLayer = new WSGameBackGroundLayer();
        _gameBackGroundLayer->initWithScene(this);
        _gameBackGroundLayer->setAnchorPoint(ccp(0, 0));
        _gameBackGroundLayer->setPosition(ccp(0, 0));
        this->addChild(_gameBackGroundLayer);
        _gameBackGroundLayer->autorelease();
        
        _gameLayer = new WSGameLayer();
        _gameLayer->initWithGameScene(this);
        _gameLayer->setAnchorPoint(ccp(0, 0));
        _gameLayer->setPosition(ccp(0, 0));
        this->addChild(_gameLayer);
        _gameLayer->autorelease();

        _joyStick = new CCJoystick;
        _joyStick->setScale(3);
        _joyStick->init(10, 20, false, true, false, false);
        _joyStick->setAnchorPoint(ccp(0, 0));
        _joyStick->setPosition(ccp(160, 350));
        this->addChild(_joyStick);
        _joyStick->autorelease();
        _joyStick->setBallTexture("joystick.png");
        _joyStick->setDelegate(this);
        
        return true;
    }
    return false;
}

void
WSGameScene::onCCJoyStickUpdate(CCNode* sender, float angle, CCPoint direction, float power)
{
    
}
