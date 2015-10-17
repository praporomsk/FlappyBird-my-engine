//
//  FBButton.cpp
//  Flappy Bird
//
//  Created by Roman Semenov on 10/12/15.
//  Copyright © 2015 Roman. All rights reserved.
//

#include "FBButton.h"
#include "FBHelper.h"
#include "FBConstants.h"

FBButton::FBButton(const char *fileName) : FBSprite(fileName)
{
    
}

bool FBButton::init(const ButtonCallback& callback)
{
    setTouchEnabled(true);
    FBTouchDispatcher::getInstance()->addTouchObject(this);

    _callback = callback;
    return true;
}

FBButton::~FBButton()
{
    FBTouchDispatcher::getInstance()->removeTouchObject(this);
}

void FBButton::touches(const FBTouches& toches, FBTouchEventType touchType)
{
    for (FBTouches::const_iterator it = toches.begin(); it != toches.end(); ++it)
        if (rectContainsPoint(getCollisionBox(), {it->x, it->y}))
            onTap(touchType);
}

void FBButton::onTap(FBTouchEventType touchType)
{
    if (!_touchEnabled)
        return;
    
    if (touchType == TOUCH_EVENT_BEGAN) {
        setScale(globalScale * 0.9);
    }else if (touchType == TOUCH_EVENT_ENDED){
        setScale(globalScale);
        if( _callback )
            _callback(this);
    }
}