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

using namespace cocos2d;
class WSGameCore;

class WSGameScene:public CCScene {
protected:
    WSGameCore*         _gameCore;
    
public:
    WSGameCore*         getGameCore();
    
    void                drawScene();
    void                drawTimeLabel();
};


#endif /* defined(__snake__WSGameScene__) */
