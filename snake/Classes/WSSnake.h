//
//  WSSnake.h
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-7.
//
//

#ifndef __snake__WSSnake__
#define __snake__WSSnake__

#include <iostream>
#include "cocos2d.h"
#include "WSType.h"
#include <vector>
#include "CCArray.h"
#include "WSMap.h"

class WSSnake {
protected:
    WSSnakeDirection    _direction;
    cocos2d::CCArray*   _positions;
    WSSnakeDirection    getDirectionRev();
public:
    uint16_t            getSnakeLength();
    WSSnakeDirection    getDirection();
    void                setDirection(WSSnakeDirection   direction);
    
    cocos2d::CCArray*   getPositions();
    void                addSnakeBody();

    void                initWithDirectionLengthAndFirstPos(WSSnakeDirection direction, uint16_t length, WSPoint* pos);
    void                move();
    WSPoint*            getNextHeadPos();
    void                calcDirection(WSSnake* snakeA, WSMap* map, WSPoint* food);
    ~WSSnake();
    bool                pointNotInSelf(WSPoint* point);
};

#endif /* defined(__snake__WSSnake__) */
