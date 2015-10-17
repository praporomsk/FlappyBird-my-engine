//
//  FBTexture.h
//  Flappy Bird
//
//  Created by Roman Semenov on 03.10.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBTexture_h
#define FBTexture_h

#include <iostream>
#include <OpenGLES/ES2/gl.h>

#include "FBImage.h"
#include "FBTypes.h"

class FBTexture {
public:
    explicit FBTexture(FBImage* image);
    GLuint getName() {return _name; }
    const FBSize& getSize() { return _size;}
private:
    void initWithData(unsigned char *data, const FBSize& size);
    GLuint _name;
    FBSize _size;
};
#endif /* FBTexture_h */
