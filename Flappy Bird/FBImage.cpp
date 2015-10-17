//
//  FBImage.cpp
//  Flappy Bird
//
//  Created by Roman Semenov on 27.09.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#include "FBImage.h"
#include "FBHelper_ios.h"

FBImage::FBImage(const char *fileName)
{
    _imageInfo = getImageDataIOS(fileName);
}