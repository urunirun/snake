//
//  WSGamePlayScene.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-4-13.
//
//

#include "WSGamePlayScene.h"

bool WSGamePlayScene::initWithGameCoreModeAndLevel(WSGameMode mode, uint16_t level)
{
    if (WSGameScene::initWithGameCoreModeAndLevel(mode, level))
    {
        
        return true;
    }
    return false;
}

void
WSGamePlayScene::onCCJoyStickUpdate(CCNode* sender, float angle, CCPoint direction, float power)
{
    WSSnake* snake = _gameCore->getSnakeA();
    
    if (direction.x > 0 && direction.x > fabs(direction.y) && kRight != snake->getDirectionRev())
        snake->setDirection(kRight);
    
    if (direction.x < 0 && -direction.x > fabs(direction.y)&& kLeft != snake->getDirectionRev())
        snake->setDirection(kLeft);
    
    if (direction.y > 0 && direction.y > fabs(direction.x) && kUp != snake->getDirectionRev())
        snake->setDirection(kUp);
    if (direction.y < 0 && direction.y < fabs(direction.y) && kDown != snake->getDirectionRev())
        snake->setDirection(kDown);
}