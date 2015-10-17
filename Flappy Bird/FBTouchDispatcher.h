//
//  FBTouchDispatcher.h
//  Flappy Bird
//
//  Created by Roman Semenov on 27.09.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBTouchDispatcher_h
#define FBTouchDispatcher_h

#include <iostream>
#include "FBTypes.h"

class FBTouchObject {
public:
    virtual void touches(const FBTouches& toches, FBTouchEventType touchType) = 0;
};

typedef std::vector<FBTouchObject*> FBTouchObjects;

class FBTouchDispatcher {
public:
    static FBTouchDispatcher *getInstance();
    void handleTouches(FBTouchEventType type, int num, intptr_t ids[], float xs[], float ys[]);
    void addTouchObject(FBTouchObject* obj);
    void removeTouchObject(FBTouchObject* obj);
private:
    FBTouchDispatcher();
    float _screenHeight;
    
    FBTouchObjects _objects;
};
#endif /* FBTouchDispatcher_h */
