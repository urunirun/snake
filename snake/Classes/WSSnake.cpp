//
//  WSSnake.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-7.
//
//

#include "WSSnake.h"

using namespace cocos2d;
const static int d[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

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

WSSnakeDirection
WSSnake::getDirectionRev()
{
    if (_direction == kUp) return kDown;
    if (_direction == kDown) return  kUp;
    if (_direction == kLeft) return  kRight;
    if (_direction == kRight) return kLeft;

    return kUp;
}

void
WSSnake::initWithDirectionLengthAndFirstPos(WSSnakeDirection direction,
                                            uint16_t length,
                                            WSPoint *pos)
{
    
    _direction = direction;
    
    WSSnakeDirection rev = this->getDirectionRev();
    _positions = CCArray::createWithObject(pos);
    
    for (int i=0; i<length-1; i++) {
        WSPoint* point =  WSPoint::pointWithInt(pos->x + (i+1)*d[rev][0],
                                                pos->y + (i+1)*d[rev][1]);
        _positions->addObject(point);
    }
    
    _positions->retain();
}

void
WSSnake::move()
{
    this->addSnakeBody();
    _positions->removeObjectAtIndex(_positions->count()-1);
}

void
WSSnake::calcDirection(WSSnake* snakeA, WSMap* map, WSPoint* food){
    WSSnakeDirection d = (WSSnakeDirection) (arc4random() % 4);
    while (d == this->getDirectionRev())
    {
        d = (WSSnakeDirection) (arc4random() % 4);
    }
    
    _direction = d;
}

bool
WSSnake::pointNotInSelf(WSPoint *point)
{
    for (int i=0; i<_positions->count(); i++) {
        if ((WSPoint*)_positions->objectAtIndex(i) == point)
        {
            return false;
        }
    }
    return true;
}

WSSnake::~WSSnake()
{
    _positions->release();
    _positions = NULL;
}