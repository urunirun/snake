//
//  WSMap.cpp
//  snake
//
//  Created by Xiaoxuan Tang on 13-3-8.
//
//

#include "WSMap.h"

#define kPtToPx 10
#define kWidth 50
#define kHegith 35

void
WSMap::initWithFile(std::string fileName)
{
    const char* path = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(fileName.c_str());
    
    FILE* mapFile = fopen(path, "r");
    fscanf(mapFile, "%hu %hu", &_width, &_height);
    
    for (int i=0; i<_width; i++) {
        _map.push_back(std::vector<WSMapNode>(_height));
    }
    
    for (int i=0; i<_height; i++) {
        for (int j=0; j<_width; j++)
        {
            
            uint16_t tmp;
            fscanf(mapFile, "%hu", &tmp);
            CCLOG("%d %d %c", j, i, tmp);
            _map[j][i] = (WSMapNode)tmp;
        }
    }
    
    
    uint16_t x, y;
    fscanf(mapFile, "%hu %hu", &x, &y);
    _firstSnakeHead = new WSPoint();
    _firstSnakeHead->initWithInt(x, y);
    
    fscanf(mapFile, "%hu %hu", &x, &y);
    _secondSnakeHead = new WSPoint();
    _secondSnakeHead->initWithInt(x, y);
}

uint16_t
WSMap::getWidth()
{
    return _width;
}

uint16_t
WSMap::getHeight()
{
    return _height;
}

WSPoint*
WSMap::getFirstSnakeHead()
{
    return _firstSnakeHead;
}

WSPoint*
WSMap::getSecondSnakeHead()
{
    return _secondSnakeHead;
}

WSMapNode
WSMap::getMapNodeByXY(uint16_t x, uint16_t y)
{
    if (checkPointlegal(WSPoint::pointWithInt(x, y)))
        return _map[x][y];
    else
        return kEdge;
}

bool
WSMap::checkPointlegal(WSPoint *point)
{
    if (point->x < 0 || point -> x >= _width)  return false;
    if (point->y < 0 || point -> y >= _height) return false;
    return true;
}

WSMap::~WSMap()
{
    _secondSnakeHead->release();
    _firstSnakeHead->release();
}