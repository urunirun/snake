//
//  WSGameLayer.h
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-13.
//
//

#ifndef __snake__WSGameLayer__
#define __snake__WSGameLayer__

#include <iostream>
#include "cocos2d.h"
#include "WSGameScene.h"

using namespace cocos2d;

class WSGameScene;

class WSGameLayer: public CCLayer {
private:
    WSGameScene*                _gameScene;
    
public:
    bool                        initWithGameScene(WSGameScene* scene);
    void                        drawSelf();
};


#endif /* defined(__snake__WSGameLayer__) */
