//
//  WSAISnake.h
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-13.
//
//

#ifndef __snake__WSAISnake__
#define __snake__WSAISnake__

#include <iostream>

#include "WSSnake.h"
#include "WSMap.h"
class WSAISnake: public WSSnake {
    
public:
    void  calcDirection(WSSnake* snakeA, WSMap* map, WSPoint* food);
};

#endif /* defined(__snake__WSAISnake__) */
