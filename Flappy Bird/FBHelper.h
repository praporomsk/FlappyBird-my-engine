//
//  FBHelper.h
//  Flappy Bird
//
//  Created by Roman Semenov on 27.09.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBHelper_h
#define FBHelper_h

#include "FBTypes.h"
#include <stdlib.h>

#define DEGREES_TO_RADIANS(__ANGLE__) ((__ANGLE__) * M_PI / 180.0f)
#define RADIANS_TO_DEGREES(__ANGLE__) ((__ANGLE__) * 180.0f / M_PI)

FBSize getWinSize();
const char* getFullPath(const char *fileName);
unsigned char* dataFromFile(const char* fileName);
bool intersectsRectAndCircle(const FBRect& rect, const FBPoint &center, float radius);
bool rectContainsPoint(const FBRect& rect, const FBPoint& point);

inline float random(float length)
{
    return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/length));
}

#endif /* FBHelper_h */
