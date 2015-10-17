//
//  FBImage.hpp
//  Flappy Bird
//
//  Created by Roman Semenov on 27.09.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBImage_h
#define FBImage_h

#include <stdio.h>
#include <iostream>
#include "FBTypes.h"

class FBImage {
public:
    explicit FBImage(const char *fileName);
    const FBImageInfo& getImageInfo() const {return _imageInfo;}
private:
    FBImageInfo _imageInfo;
};
#endif /* FBImage_hpp */
