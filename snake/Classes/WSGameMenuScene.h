//
//  WSGameMenuScene.h
//  snake
//
//  Created by Xiaoxuan Tang on 13-4-1.
//
//

#ifndef __snake__WSGameMenuScene__
#define __snake__WSGameMenuScene__

#include <iostream>
#include "cocos2d.h"

#include "WSBackGroundLayer.h"
#include "WSGameLayer.h"
#include "CCJoyStick.h"
#include "WSGameScene.h"
using namespace cocos2d;

class WSGameMenuScene: public WSGameScene, CCJoyStickDelegate {
private:
    WSBackGroundLayer*                  _backGroundLayer;
    WSGameLayer*                        _gameLayer;
    CCJoystick*                         _joyStick;
    
    void onCCJoyStickUpdate(CCNode* sender, float angle, CCPoint direction, float power);
    void onCCJoyStickActivated(CCNode* sender){CC_UNUSED_PARAM(sender);}
    void onCCJoyStickDeactivated(CCNode* sender){CC_UNUSED_PARAM(sender);}
    
public:
    bool                                init();
};

#endif /* defined(__snake__WSGameMenuScene__) */
