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

float_t
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
WSGameCore::colisionDetection()
{
    WSPoint* snakeHeadA = _snakeA->getNextHeadPos();
    WSPoint* snakeHeadB = _snakeB->getNextHeadPos();
    
    if ((*snakeHeadA) == snakeHeadB)
    {
        _gameOverFlag = (WSGameOverFlag)(kSnakeADie | kSnakeBDie);
        return;
    }
    
    for (int i=0; i<_snakeA->getPositions()->count(); i++) {
        WSPoint* point = (WSPoint*)_snakeA->getPositions()->objectAtIndex(i);
        if ((*snakeHeadB) == point)
        {
            _gameOverFlag = (WSGameOverFlag) (_gameOverFlag | kSnakeBDie);
            break;
        }
    }
    
    for (int i=0; i<_snakeB->getPositions()->count(); i++)
    {
        WSPoint* point = (WSPoint*) _snakeB->getPositions()->objectAtIndex(i);
        if ((*snakeHeadA) == point)
        {
            _gameOverFlag = (WSGameOverFlag) (_gameOverFlag | kSnakeADie);
            break;
        }
    }
}

void
WSGameCore::tick(float_t dt)
{
    
    
    WSPoint* snakeANextHeadPos = _snakeA->getNextHeadPos();
    if (_map->checkPointlegal(snakeANextHeadPos))
    {
        if ((*snakeANextHeadPos) == _foodPosition)
        {
            _foodPosition->x = -1;
            _foodPosition->y = -1;
            _scoreA ++;
            _snakeA->addSnakeBody();
        }
        else
            _snakeA->move();
    }
    else
    {
        _gameOverFlag = (WSGameOverFlag)(_gameOverFlag | kSnakeADie);
    }
    
    if (_mode == kComputer)
    {
        WSPoint* snakeBNextHeadPos = _snakeB->getNextHeadPos();
        if (_map->checkPointlegal(snakeBNextHeadPos))
        {
            if ((*snakeBNextHeadPos) == _foodPosition)
            {
                _foodPosition->x = -1;
                _foodPosition->y = -1;
                _scoreB ++;
                _snakeB->addSnakeBody();
            }
            else
                _snakeB->move();
        }
        else
        {
            _gameOverFlag = (WSGameOverFlag) (_gameOverFlag | kSnakeBDie);
        }
    }
    
    this->colisionDetection();
    
    if (_gameOverFlag != kNoBodyDie)
    {
        gameOver();
    }
    
    if (_foodPosition->x == -1 && _foodPosition->y == -1)
    {
        genFoodPos();
    }
    
    _gameScene->drawScene();
}

void
WSGameCore::update(float_t dt)
{
    _remainTime += dt;
    _gameScene->drawTimeLabel();
}