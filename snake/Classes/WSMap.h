//
//  WSMap.h
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-8.
//
//

#ifndef __snake__WSMap__
#define __snake__WSMap__

#include <iostream>
#include <vector>

#include "WSType.h"

class WSMap {
private:
    uint16_t                                _width;
    uint16_t                                _height;
    std::vector<std::vector<WSMapNode> >    _map;
    WSPoint*                                _firstSnakeHead;
    WSPoint*                                _secondSnakeHead;
    
public:
    void        initWithFile(std::string fileName);
    uint16_t    getWidth();
    uint16_t    getHeight();
    WSPoint*    getFirstSnakeHead();
    WSPoint*    getSecondSnakeHead();
    
    WSMapNode   getMapNodeByXY(uint16_t x, uint16_t y);
    bool        checkPointlegal(WSPoint* point);
    ~WSMap();
};

#endif /* defined(__snake__WSMap__) */
