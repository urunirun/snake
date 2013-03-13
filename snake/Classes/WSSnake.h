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

class WSSnake {
protected:
    WSSnakeDirection    _direction;
    cocos2d::CCArray*   _positions;
public:
    uint16_t            getSnakeLength();
    WSSnakeDirection    getDirection();
    void                setDirection(WSSnakeDirection   direction);
    
    cocos2d::CCArray*   getPositions();
    void                addSnakeBody(WSPoint* point);

    void                initWithDirectionLengthAndFirstPos(WSSnakeDirection direction, uint16_t length, WSPoint* pos);
    ~WSSnake();
};

#endif /* defined(__snake__WSSnake__) */
