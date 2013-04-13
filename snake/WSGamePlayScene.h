//
//  WSGamePlayScene.h
//  snake
//
//  Created by Xiaoxuan Tang on 13-4-13.
//
//

#ifndef __snake__WSGamePlayScene__
#define __snake__WSGamePlayScene__

#include <iostream>

#include "cocos2d.h"

#include "CCJoyStick.h"
#include "WSGameScene.h"

using namespace cocos2d;

class WSGamePlayScene: public WSGameScene {
private:
    void                onCCJoyStickUpdate(CCNode* sender, float angle, CCPoint direction, float power);
public:
    bool                initWithGameCoreModeAndLevel(WSGameMode mode, uint16_t level);
};


#endif /* defined(__snake__WSGamePlayScene__) */
