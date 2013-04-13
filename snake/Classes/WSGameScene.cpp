//
//  WSGameScene.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-13.
//
//

#include "WSGameScene.h"
#include "WSGameMenuScene.h"

void
WSGameScene::drawScene()
{
    _gameLayer->drawSelf();
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
WSGameScene::initWithGameCoreModeAndLevel(WSGameMode mode, uint16_t level)
{
    if (CCScene::init())
    {
        _gameCore = new WSGameCore;
        _gameCore->initWithGameModeAndMapName(mode, level, this);
        
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
        
        CCMenuItemImage* btn = CCMenuItemImage::create("btn.png", "btn.png", this, menu_selector(WSGameScene::btnClick));
        
        btn->setPosition(ccp(980, 350));
        btn->setScale(2.5);
        CCMenu* menu = CCMenu::createWithItem(btn);
        menu->setAnchorPoint(ccp(0, 0));
        menu->setPosition(ccp(0, 0));
        this->addChild(menu);
        
        this->startGame();
        return true;
    }
    return false;
}

void
WSGameScene::startGame()
{
    schedule(schedule_selector(WSGameScene::tick) , _gameCore->getSpeed());
    scheduleUpdate();
}

void
WSGameScene::tick(float_t dt)
{
    _gameCore->tick(dt);
    
    if (_gameCore->getFin())
    {
        unschedule(schedule_selector(WSGameScene::tick));
        unscheduleUpdate();

        if (_gameCore->getGameMode() == kShow)
        {
            delete _gameCore;
            _gameCore = new WSGameCore;
            _gameCore -> initWithGameModeAndMapName(kShow, 0, this);
            
            return;
        }
        
        CCLabelTTF* label;
        if (_gameCore->getGameOverFlag() == kSnakeADie)
        {
            label = CCLabelTTF::create("You Lose", "ArialMT", 30);
        }
        
        if (_gameCore->getGameOverFlag() == kSnakeBDie)
        {
            label = CCLabelTTF::create("You Lose", "ArialMT", 30);
        }
        
        if (_gameCore->getGameOverFlag() == (kSnakeBDie | kSnakeADie))
        {
            label = CCLabelTTF::create("Tie", "ArialMT", 30);
        }
        
        
        label->setColor(ccc3(255, 0, 0));
        label->setPosition(ccp(568, 320));
        this->addChild(label);
        this->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(3), CCCallFunc::create(this, callfunc_selector(WSGameScene::gameOver))));
    }
}

void
WSGameScene::gameOver()
{
    WSGameMenuScene* scene = new WSGameMenuScene;
    scene->init();
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(.5f, scene));
    scene->autorelease();
}

void
WSGameScene::update(float_t dt)
{
    _gameCore->update(dt);
}

void
WSGameScene:: btnClick()
{

}
void
WSGameScene::onCCJoyStickUpdate(CCNode* sender, float angle, CCPoint direction, float power)
{
    
}
