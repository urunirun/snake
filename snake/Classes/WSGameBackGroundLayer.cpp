//
//  WSGameBackGroundLayer.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-4-13.
//
//

#include "WSGameBackGroundLayer.h"

bool
WSGameBackGroundLayer::initWithScene(WSGameScene *scene)
{
    if (CCLayer::init())
    {
        
        CCLayerColor* whiteBg = CCLayerColor::create(ccc4(255, 255, 255, 255), 500, 350);
        whiteBg->setAnchorPoint(ccp(0, 0));
        whiteBg->setPosition(ccp(320, 170));
        this->addChild(whiteBg);
        
        WSMap* map = scene->getGameCore()->getGameMap();
        
        for (int i=0; i<map->getHeight(); i++) {
            for (int j=0; j<map->getWidth(); j++) {
                if (map->getMapNodeByXY(j, i) == kEdge)
                {
                    CCSprite* sprite = CCSprite::create("edge.png");
                    sprite->setAnchorPoint(ccp(0, 0));
                    sprite->setPosition(ccp(320+ j*sprite->boundingBox().size.width, 170 + (map->getHeight()-i-1)*sprite->boundingBox().size.height));
                    this->addChild(sprite);
                }
            }
        }

        return true;
    }
    return false;
}