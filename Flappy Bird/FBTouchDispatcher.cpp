//
//  FBTouchDispatcher.cpp
//  Flappy Bird
//
//  Created by Roman Semenov on 27.09.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#include "FBTouchDispatcher.h"
#include "FBHelper.h"

using namespace std;

FBTouchDispatcher* FBTouchDispatcher::getInstance()
{
    static FBTouchDispatcher *pDispatcher = nullptr;
    if (pDispatcher == nullptr)
        pDispatcher = new FBTouchDispatcher();
    
    return pDispatcher;
}

FBTouchDispatcher::FBTouchDispatcher()
{
    _screenHeight = getWinSize().height;
    _objects.reserve(3);
}

void FBTouchDispatcher::addTouchObject(FBTouchObject* obj)
{
    _objects.push_back(obj);
}

void FBTouchDispatcher::removeTouchObject(FBTouchObject* obj)
{
    _objects.erase( remove( _objects.begin(), _objects.end(), obj ), _objects.end() );
}

void FBTouchDispatcher::handleTouches(FBTouchEventType type, int num, intptr_t ids[], float xs[], float ys[])
{
    static FBTouches toches;
    for (int i = 0; i < num; ++i)
        toches.push_back({xs[i], _screenHeight - ys[i]});
    
    for (FBTouchObjects::iterator it = _objects.begin(); it !=_objects.end(); ++it)
        (*it)->touches(toches, type);
    
    toches.clear();
}