//
//  WSGameBackGroundLayer.h
//  snake
//
//  Created by Xiaoxuan Tang on 13-4-13.
//
//

#ifndef __snake__WSGameBackGroundLayer__
#define __snake__WSGameBackGroundLayer__

#include <iostream>
#include "cocos2d.h"
#include "WSGameScene.h"
using namespace cocos2d;

class WSGameScene;

class WSGameBackGroundLayer: public CCLayer {
    
public:
    bool                initWithScene(WSGameScene* scene);
};

#endif /* defined(__snake__WSGameBackGroundLayer__) */
