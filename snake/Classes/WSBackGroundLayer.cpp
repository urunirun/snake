//
//  WSBackGroundLayer.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-4-1.
//
//

#include "WSBackGroundLayer.h"

bool
WSBackGroundLayer::init()
{
    if (CCLayer::init())
    {
        CCSprite* bgImage = CCSprite::create("gameBackGround.png");
        bgImage->setPosition(ccp(0,0));
        bgImage->setAnchorPoint(ccp(0,0));
        this->addChild(bgImage);
        
        return true;
    }
    return false;
}