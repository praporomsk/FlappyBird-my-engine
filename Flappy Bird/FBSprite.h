//
//  FBSprite.hpp
//  Flappy Bird
//
//  Created by Roman Semenov on 03.10.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBSprite_h
#define FBSprite_h

#include "FBNode.h"
#include "FBTexture.h"
#include "FBMath.h"

class FBSprite : public FBNode {
public:
    explicit FBSprite(const char *fileName);
    virtual ~FBSprite();
    
    virtual void render();
    virtual void setPosition(const FBPoint &position);
    virtual void setPosition(float x, float y);
    virtual void setRotation(const float rotation);
    
    virtual FBRect getBoundingBox();
    virtual FBRect getCollisionBox();
    virtual void setTexture(const char *fileName);
    
protected:
    void updatePosition();
    virtual void transform();
    
    FBTexture *_texture;
private:
    GLuint _textureLocation;
    GLuint _colorLocation;
    GLuint _texCoordsLocation;
    GLuint _mvLocation;
    GLuint _positionLocation;
    GLuint _vertexBuffer;
    GLuint _indexBuffer;
    
    FBVertex _vertices[4];
    Matrix4f _transformation;

    FBSize _winSize;
};
#endif /* FBSprite_h */
