//
//  WSGameLayer.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-13.
//
//

#include "WSGameLayer.h"
//#include "WSMap.h"
void
WSGameLayer::drawSelf()
{
    this->removeAllChildrenWithCleanup(true);
    WSMap* map = _gameScene->getGameCore()->getGameMap();
    
    WSSnake* snake = _gameScene->getGameCore()->getSnakeA();
    CCArray* arr = snake->getPositions();
    
    for (int i=0; i<arr->count(); i++) {
        WSPoint* point = (WSPoint*) arr->objectAtIndex(i);
        CCSprite* sprite = CCSprite::create("snake1.png");
        
        sprite->setAnchorPoint(ccp(0, 0));
        sprite->setPosition(ccp(320+ point->x*sprite->boundingBox().size.width, 170 + (map->getHeight()-point->y-1)*sprite->boundingBox().size.height));
        this->addChild(sprite);
    }
    
    snake = _gameScene->getGameCore()->getSnakeB();
    if (snake)
    {
        CCArray* arr = snake->getPositions();
        
        for (int i=0; i<arr->count(); i++) {
            WSPoint* point = (WSPoint*) arr->objectAtIndex(i);
            CCSprite* sprite = CCSprite::create("snake2.png");
            
            sprite->setAnchorPoint(ccp(0, 0));
            sprite->setPosition(ccp(320+ point->x*sprite->boundingBox().size.width, 170 + (map->getHeight()-point->y-1)*sprite->boundingBox().size.height));
            this->addChild(sprite);
        }
    }
    
    WSPoint* point = _gameScene->getGameCore()->getFoodPosition();
    CCSprite* sprite = CCSprite::create("food.png");
    
    sprite->setAnchorPoint(ccp(0, 0));
    sprite->setPosition(ccp(320+ point->x*sprite->boundingBox().size.width, 170 + (map->getHeight()-point->y-1)*sprite->boundingBox().size.height));
    this->addChild(sprite);
}

bool
WSGameLayer::initWithGameScene(WSGameScene *scene)
{
    if (CCLayer::init())
    {
        _gameScene = scene;
        this->drawSelf();
        
        return true;
    }
    return false;
}