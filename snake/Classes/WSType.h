//
//  WSType.h
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-7.
//
//

#ifndef snake_WSType_h
#define snake_WSType_h

#include "cocos2d.h"

using namespace cocos2d;

class WSPoint: public CCObject {
public:
    
    uint16_t    x, y;
    
    
    void initWithInt(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    
    static WSPoint* pointWithInt(int x, int y)
    {
        WSPoint* point = new WSPoint();
        point->initWithInt(x, y);
        point->autorelease();
        return point;
    }
    
    bool operator == (WSPoint* b)
    {
        return x == b->x && y == b-> y;
    }
};


enum WSSnakeDirection {
    kUp = 0,
    kDown,
    kLeft,
    kRight
};

enum WSMapNode {
    kEmpty,
    kEdge
};

enum WSGameMode {
    kSingle,
    kComputer,
    kShow
    };

enum WSGameOverFlag {
    kNoBodyDie = 0,
    kSnakeADie = 1<<0,
    kSnakeBDie = 1<<1
    };

#endif
