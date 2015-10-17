//
//  FBTexture.cpp
//  Flappy Bird
//
//  Created by Roman Semenov on 03.10.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#include "FBTexture.h"

FBTexture::FBTexture(FBImage* image)
{
    initWithData(image->getImageInfo().data, image->getImageInfo().size);
}

void FBTexture::initWithData(unsigned char *data,  const FBSize& size)
{
    glGenTextures(1, &_name);
    glBindTexture(GL_TEXTURE_2D, _name);
    
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, size.width, size.height, 0, GL_RGBA, GL_UNSIGNED_BYTE,(GLubyte *)data);
    
    _size = size;
  
    delete data;
}

