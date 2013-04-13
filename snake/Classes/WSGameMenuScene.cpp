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
    if (WSGameScene::initWithGameCoreModeAndLevel(kShow, 0))
    {
                
        CCSprite*   menuImage = CCSprite::create("menuLayer.png");
        menuImage->setAnchorPoint(ccp(0, 1));
        menuImage->setPosition(ccp(320, 520));
        this->addChild(menuImage);
        
        
        return true;
    }
    return false;
}


void
WSGameMenuScene::onCCJoyStickUpdate(CCNode* sender, float angle, CCPoint direction, float power)
{
    CCLOG("%f %f", direction.x, direction.y);
}
