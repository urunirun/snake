//
//  WSGameCore.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-13.
//
//

#include "WSGameCore.h"

#define kSingleMap      ""
#define kShowMap        ""

#define kComputerEasy   ""
#define kComputerNormal ""
#define kComputerHard   ""

#define kEasySpeed      1.5
#define kNormalSpeed    1.2
#define kHardSpeed      1

WSSnake*
WSGameCore::getSnakeA()
{
    return _snakeA;
}

WSSnake*
WSGameCore::getSnakeB()
{
    return _snakeB;
}

WSGameMode
WSGameCore::getGameMode()
{
    return _mode;
}

WSMap*
WSGameCore::getGameMap()
{
    return _map;
}

WSPoint*
WSGameCore::getFoodPosition()
{
    return _foodPosition;
}

uint16_t
WSGameCore::getGameLevel()
{
    return _level;
}

uint16_t
WSGameCore::getScoreA()
{
    return _scoreA;
}

uint16_t
WSGameCore::getScoreB()
{
    return _scoreB;
}

uint16_t
WSGameCore::getRemainTime()
{
    return _remainTime;
}

void
WSGameCore::initWithGameModeAndMapName(WSGameMode   mode,
                                       uint16_t     level,
                                       WSGameScene* gameScene)
{
    _mode = mode;
    _level = level;
    _gameScene = gameScene;
    
    if (_mode == kSingle || _mode == kShow)
    {
        _map = new WSMap();
        if (_mode == kSingle)
            _map->initWithFile(kSingleMap);
        else
            _map->initWithFile(kShowMap);
        
        _snakeA = new WSSnake();
        _snakeA ->initWithDirectionLengthAndFirstPos(kRight, 4, _map->getFirstSnakeHead());
        _snakeB = NULL;
        _speed = kEasySpeed;
        _level = 1;
        _scoreA = 0;
    }
    
    if (_mode == kComputer)
    {
        _snakeA = new WSSnake();
        _snakeA -> initWithDirectionLengthAndFirstPos(kRight, 4, _map->getFirstSnakeHead());
        
        _snakeB = new WSSnake();
        _snakeB -> initWithDirectionLengthAndFirstPos(kLeft, 4, _map->getSecondSnakeHead());
        
        if (level == 0)
        {
            _speed = kEasySpeed;
            _map -> initWithFile(kComputerEasy);
        }
        
        if (level == 1)
        {
            _map -> initWithFile(kComputerNormal);
            _speed = kNormalSpeed;
        }
        
        if (level == 1)
        {
            _map -> initWithFile(kComputerHard);
            _speed = kHardSpeed;
        }
        
        _scoreA = 0;
        _scoreB = 0;

    }
}

void
WSGameCore::startGame()
{
    schedule(schedule_selector(WSGameCore::tick) , _speed);
    scheduleUpdate();
}

void
WSGameCore::tick(float_t dt)
{
    
}

void
WSGameCore::update(float_t dt)
{
    
}