//
//  Constants.h
//  Flappy Bird
//
//  Created by Roman Semenov on 10/11/15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef Constants_h
#define Constants_h

#include "FBTypes.h"
#include "FBHelper.h"

const float kFBPipesNum = 3;
const float kFBGroundNum = 3;
const float kFBDisBetweenPipesX = 250;
const float kFBDisBetweenPipesY = 150;
const float kFBFirstPipePosX = 500;
const FBRange kFBRandomPipeYpos = {200 , 175};

const float kFBTapVelocityY = 13;
const float kFBGravity = 40;
const float kFBBirdSpeed = 200;

const float globalScale = getWinSize().height / 511.0f;

#endif /* Constants_h */
