//
//  WSGameLayer.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-13.
//
//

#include "WSGameLayer.h"

bool
WSGameLayer::init()
{
    if (CCLayer::init())
    {
        CCLayerColor* whiteBg = CCLayerColor::create(ccc4(255, 255, 255, 255), 500, 347);
        whiteBg->setAnchorPoint(ccp(0, 0));
        whiteBg->setPosition(ccp(320, 170));
        this->addChild(whiteBg);
        
        return true;
    }
    return false;
}