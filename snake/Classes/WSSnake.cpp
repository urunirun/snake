//
//  WSSnake.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-7.
//
//

#include "WSSnake.h"

using namespace cocos2d;

uint16_t WSSnake::getSnakeLength()
{
    return _positions->count();
}

WSSnakeDirection WSSnake::getDirection()
{
    return _direction;
}

void WSSnake::setDirection(WSSnakeDirection direction)
{
    _direction = direction;
}

CCArray* WSSnake::getPositions()
{
    return _positions;
}

void WSSnake::addSnakeBody(WSPoint* point)
{
    _positions->insertObject(point, 0);
}

void WSSnake::initWithDirectionLengthAndFirstPos(WSSnakeDirection direction,
                                                 uint16_t length,
                                                 WSPoint *pos)
{
    const int d[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    _direction = direction;
    _positions = CCArray::createWithObject(pos);
    
    for (int i=0; i<length-1; i++) {
        WSPoint* point =  WSPoint::pointWithInt(pos->x + d[direction][0],
                                                pos->y + d[direction][1]);
        _positions->addObject(point);
    }
}

WSSnake::~WSSnake()
{
    _positions->release();
    _positions = NULL;
}