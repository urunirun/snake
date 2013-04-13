//
//  WSGameMenuScene.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-4-1.
//
//

#define kBallY1 302
#define kBallY2 240
#include "WSGameMenuScene.h"
#include "WSGamePlayScene.h"
bool
WSGameMenuScene::init()
{
    if (WSGameScene::initWithGameCoreModeAndLevel(kShow, 0))
    {
                
        CCSprite*   menuImage = CCSprite::create("menuLayer.png");
        menuImage->setAnchorPoint(ccp(0, 1));
        menuImage->setPosition(ccp(320, 520));
        this->addChild(menuImage);
        
        CCSprite*   menuBall =  CCSprite::create("ball.png");
        menuBall-> setAnchorPoint(ccp(0, 0));
        menuBall-> setPosition(ccp(480, kBallY1));
        menuBall-> setScale(.5);
        menuBall-> setTag(1);
        this->addChild(menuBall);
        
        _menuStatus = false;
        
        return true;
    }
    return false;
}

void
WSGameMenuScene::btnClick()
{
    WSGamePlayScene* scene = new WSGamePlayScene;
    if (_menuStatus)
    {
        scene->initWithGameCoreModeAndLevel(kComputer, 0);
    }
    else
    {
        scene->initWithGameCoreModeAndLevel(kSingle, 0);
    }
    
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(.5, scene));
    scene->autorelease();
}

void
WSGameMenuScene::onCCJoyStickUpdate(CCNode* sender, float angle, CCPoint direction, float power)
{
    CCNode* node = this->getChildByTag(1);
    if (_menuStatus && direction.y > 0)
    {
        node->setPosition(ccp(480, kBallY1));
        _menuStatus = false;
    }
    if (!_menuStatus && direction.y < 0)
    {
        node->setPosition(ccp(480, kBallY2));
        _menuStatus = true;
    }
}
