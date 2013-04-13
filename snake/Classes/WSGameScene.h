//
//  WSGameScene.h
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-13.
//
//

#ifndef __snake__WSGameScene__
#define __snake__WSGameScene__

#include <iostream>

#include "cocos2d.h"
#include "WSGameCore.h"

#include "WSGameLayer.h"
#include "WSGameBackGroundLayer.h"
#include "WSBackGroundLayer.h"
#include "CCJoyStick.h"

using namespace cocos2d;
class WSGameCore;
class WSGameLayer;
class WSGameBackGroundLayer;

class WSGameScene:public CCScene, CCJoyStickDelegate{
protected:
    WSGameCore*             _gameCore;
    WSGameLayer*            _gameLayer;
    WSGameBackGroundLayer*  _gameBackGroundLayer;
    WSBackGroundLayer*      _backGroundLayer;
    
    CCJoystick*             _joyStick;
    
    void                    onCCJoyStickUpdate(CCNode* sender, float angle, CCPoint direction, float power);
    void                    onCCJoyStickActivated(CCNode* sender){CC_UNUSED_PARAM(sender);}
    void                    onCCJoyStickDeactivated(CCNode* sender){CC_UNUSED_PARAM(sender);}
    void                    startGame();
public:
    WSGameCore*             getGameCore();
    void                    gameOver();
    void                    drawScene();
    void                    drawTimeLabel();
    bool                    initWithGameCoreModeAndLevel(WSGameMode mode, uint16_t level);
    virtual void            btnClick();
    void                    tick(float_t dt);         //schedule All frames
    void                    update(float_t dt);        //schedule time
    
};


#endif /* defined(__snake__WSGameScene__) */
