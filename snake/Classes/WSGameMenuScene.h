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

using namespace cocos2d;

class WSGameMenuScene: public CCScene {
private:
    WSBackGroundLayer*                  _backGroundLayer;
    
public:
    bool                                init();
};

#endif /* defined(__snake__WSGameMenuScene__) */
