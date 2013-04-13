//
//  WSGameCore.h
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-13.
//
//

#ifndef __snake__WSGameCore__
#define __snake__WSGameCore__

#include <iostream>

#include "WSSnake.h"
#include "WSMap.h"
#include "WSType.h"
#include "WSGameScene.h"

#include "cocos2d.h"
using namespace cocos2d;

class WSGameScene;

class WSGameCore: public CCNode{  //why it is CCNode.. Because CCSchedule relay on CCObject
private:
    WSSnake*        _snakeA;
    WSSnake*        _snakeB;
    
    WSGameMode      _mode;
    
    WSMap*          _map;
    WSPoint*        _foodPosition;
    
    uint16_t        _level;
    uint16_t        _scoreA;
    uint16_t        _scoreB;
    
    float_t         _speed;                 //schedule time interval
    float_t         _remainTime;
    
    WSGameScene*    _gameScene;
    WSGameOverFlag  _gameOverFlag;
    
    void            gameOver();
    void            colisionDetection();
    void            genFoodPos();
    
public:
    WSSnake*        getSnakeA();
    WSSnake*        getSnakeB();
    WSGameMode      getGameMode();
    WSMap*          getGameMap();
    WSPoint*        getFoodPosition();
    
    uint16_t        getGameLevel();
    uint16_t        getScoreA();
    uint16_t        getScoreB();
    float_t         getRemainTime();
    
    void            initWithGameModeAndMapName(WSGameMode   mode,
                                               uint16_t     level,
                                               WSGameScene* gameScene);
    
    void            startGame();
    void            tick(float_t dt);         //schedule All frames
    void            update(float_t dt);        //schedule time
    
    ~WSGameCore();
};

#endif /* defined(__snake__WSGameCore__) */
