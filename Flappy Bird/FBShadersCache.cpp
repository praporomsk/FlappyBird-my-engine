//
//  FBShadersCache.cpp
//  Flappy Bird
//
//  Created by Roman Semenov on 03.10.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#include "FBShadersCache.h"

FBShadersCache *FBShadersCache::getInstance()
{
    static FBShadersCache *instance = NULL;
    if (instance == NULL) {
        instance = new FBShadersCache();
    }
    
    return instance;
}

FBShadersCache::FBShadersCache()
{
    for (int i = 0; i < SHADERS_SIZE; i++)
        _shaders[(FBShaderType)i] = new FBShaderProgram(shaderNames[i]);
}

FBShaderProgram *FBShadersCache::getProgram(FBShaderType type)
{
    Shaders_t::iterator it = _shaders.find(type);
    if (it == _shaders.end())
        return nullptr;
    
    return it->second;
}