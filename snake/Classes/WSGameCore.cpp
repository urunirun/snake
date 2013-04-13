//
//  WSGameCore.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-13.
//
//

#include "WSGameCore.h"

#define kSingleMap      "easy_map"
#define kShowMap        "easy_map"

#define kComputerEasy   "easy_map"
#define kComputerNormal "easy_map"
#define kComputerHard   "easy_map"

#define kEasySpeed      .05
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

float_t
WSGameCore::getSpeed()
{
    return _speed;
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
        {
            _map->initWithFile(kSingleMap);
            _snakeA = new WSSnake();
        }
        else
        {
            _map->initWithFile(kShowMap);
            _snakeA = new WSSnake();
        }
        
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
    
    _foodPosition = new WSPoint;
    this->genFoodPos();
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
WSGameCore::genFoodPos()
{
    std::vector< std::vector<bool> > map(_map->getWidth());
    for (int i=0; i<_map->getWidth(); i++) {
        map.push_back(std::vector<bool>(_map->getHeight()));
        for (int j=0; j<_map->getHeight(); j++) {
            map[i][j] = (_map->getMapNodeByXY(i, j) != kEdge);
        }
    }
    
    for (int i=0; i<_snakeA->getPositions()->count(); i++) {
        WSPoint* pos = (WSPoint*)_snakeA->getPositions()->objectAtIndex(i);
        map[pos->x][pos->y] = false;
    }
    
    if (_snakeB)
    {
        for (int i=0; i<_snakeB->getPositions()->count(); i++) {
            WSPoint* pos = (WSPoint*)_snakeB->getPositions()->objectAtIndex(i);
            map[pos->x][pos->y] = false;
        }
    }
    
    std::vector<CCPoint> emptyArray;
    for (int i=0; i<_map->getWidth(); i++) {
        for (int j=0; j<_map->getHeight(); j++) {
            if (map[i][j])
                emptyArray.push_back(ccp(i,j));
        }
    }
    
    uint16_t pos_ = arc4random() % emptyArray.size();
    _foodPosition->x = (uint16_t) emptyArray[ pos_ ].x;
    _foodPosition->y = (int) emptyArray[ pos_ ].y;
}

void
WSGameCore::gameOver()
{
    CCLOG("GameOver!!!!!!!!");
}

void
WSGameCore::tick(float_t dt)
{
    if (_mode == kComputer)
    {
        _snakeB->calcDirection(_snakeA, _map, _foodPosition);
    }
    
    if (_mode == kShow)
    {
        _snakeA->calcDirection(_snakeA, _map, _foodPosition);
    }
    
    WSPoint* snakeANextHeadPos = _snakeA->getNextHeadPos();
    if (_map->checkPointlegal(snakeANextHeadPos) && _snakeA->pointNotInSelf(snakeANextHeadPos))
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
        if (_map->checkPointlegal(snakeBNextHeadPos) && _snakeB->pointNotInSelf(snakeBNextHeadPos))
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
    
    if (_mode == kComputer)
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

WSGameCore::~WSGameCore()
{
    delete _snakeA;
    _snakeA = NULL;
    
    delete _snakeB;
    _snakeB = NULL;
    
    delete _map;
    _map = NULL;
    
    _foodPosition->release();
    _foodPosition = NULL;
}