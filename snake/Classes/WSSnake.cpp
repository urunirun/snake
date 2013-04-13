//
//  WSSnake.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-7.
//
//

#include "WSSnake.h"

using namespace cocos2d;
const static int d[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

uint16_t
WSSnake::getSnakeLength()
{
    return _positions->count();
}

WSSnakeDirection
WSSnake::getDirection()
{
    return _direction;
}

void
WSSnake::setDirection(WSSnakeDirection direction)
{
    _direction = direction;
}

CCArray*
WSSnake::getPositions()
{
    return _positions;
}

WSPoint*
WSSnake::getNextHeadPos()
{
    WSPoint* point = (WSPoint*) _positions->objectAtIndex(0);
    return WSPoint::pointWithInt(point->x + d[_direction][0], point->y + d[_direction][1]);
}

void
WSSnake::addSnakeBody()
{
    _positions->insertObject(this->getNextHeadPos(), 0);
}

void
WSSnake::initWithDirectionLengthAndFirstPos(WSSnakeDirection direction,
                                            uint16_t length,
                                            WSPoint *pos)
{
    
    _direction = direction;
    _positions = CCArray::createWithObject(pos);
    
    for (int i=0; i<length-1; i++) {
        WSPoint* point =  WSPoint::pointWithInt(pos->x + (i+1)*d[direction][0],
                                                pos->y + (i+1)*d[direction][1]);
        _positions->addObject(point);
    }
}

void
WSSnake::move()
{
    this->addSnakeBody();
    _positions->removeObjectAtIndex(_positions->count()-1);
}

void
WSSnake::clacDirection(WSSnake* snakeA, WSMap* map, WSPoint* food){}

WSSnake::~WSSnake()
{
    _positions->release();
    _positions = NULL;
}