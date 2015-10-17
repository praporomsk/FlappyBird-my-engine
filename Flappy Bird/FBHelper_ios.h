//
//  FBHelper_ios.h
//  Flappy Bird
//
//  Created by Roman Semenov on 27.09.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBHelper_ios_h
#define FBHelper_ios_h

#include "FBTypes.h"

FBSize getWinSizeIOS();
FBImageInfo getImageDataIOS(const char *filePath);
const char* getFullPathIOS(const char *fileName);
#endif /* FBHelper_ios_h */
