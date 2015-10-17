//
//  FBShadersCache.h
//  Flappy Bird
//
//  Created by Roman Semenov on 03.10.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBShadersCache_h
#define FBShadersCache_h

#include <iostream>
#include <map>
#include "FBShaderProgram.h"
#include "FBTypes.h"

typedef std::map<FBShaderType, FBShaderProgram*> Shaders_t;

class FBShadersCache {
public:
    static FBShadersCache *getInstance();
    FBShaderProgram *getProgram(FBShaderType type);
    
private:
    FBShadersCache();
    FBShadersCache(FBShadersCache &) {}
    FBShadersCache& operator=(FBShadersCache &);
    
    void addAttributes(FBShadersCache *program, int index);
    
    Shaders_t _shaders;
};
#endif /* FBShadersCache_hpp */
