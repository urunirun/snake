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

#include "CCJoyStick.h"
#include "WSGameScene.h"

using namespace cocos2d;

class WSGameMenuScene: public WSGameScene {
private:
    void                onCCJoyStickUpdate(CCNode* sender, float angle, CCPoint direction, float power);
    bool                _menuStatus;
public:
    bool                init();
    void                btnClick();
};

#endif /* defined(__snake__WSGameMenuScene__) */
