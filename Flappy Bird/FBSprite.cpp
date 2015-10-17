//
//  FBSprite.cpp
//  Flappy Bird
//
//  Created by Roman Semenov on 03.10.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#include "FBSprite.h"

#include <math.h>
#include "FBHelper.h"

const GLubyte Indices[] = {
    1, 0, 2, 3
};

FBSprite::FBSprite(const char *fileName)
:_texture(nullptr)
{
    FBImage *image = new FBImage(fileName);
    _texture = new FBTexture(image);
    delete image;
    
    _winSize = getWinSize();
    
    updatePosition();

    
    setShaderProgram(SHADER_TEXTURE_AND_COLOR);
    getShaderProgram()->use();
    
    glGenBuffers(1, &_vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_DRAW);
    
    glGenBuffers(1, &_indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);
    
    _mvLocation = glGetUniformLocation(getShaderProgram()->getProgram(), kShaderMVUniform);
    
    _positionLocation = glGetAttribLocation(getShaderProgram()->getProgram(), kShaderPositionAttr);
    _colorLocation = glGetAttribLocation(getShaderProgram()->getProgram(), kShaderColorAttr);
    glEnableVertexAttribArray(_positionLocation);
    glEnableVertexAttribArray(_colorLocation);
    
    _texCoordsLocation = glGetAttribLocation(getShaderProgram()->getProgram(), kShaderTextureAttr);
    glEnableVertexAttribArray(_texCoordsLocation);
    _textureLocation = glGetUniformLocation(getShaderProgram()->getProgram(), kShaderTextureUniform);
}

FBSprite::~FBSprite()
{
    delete _texture;
}

void FBSprite::render()
{
    if (!isVisible())
        return;
    
    setShaderProgram(SHADER_TEXTURE_AND_COLOR);
    getShaderProgram()->use();
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glViewport(0, 0, _winSize.width, _winSize.height);
    
    glUniformMatrix4fv(_mvLocation, 1, 0, _transformation.m);
    
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _texture->getName());
    glUniform1i(_textureLocation, 0);
    
    glVertexAttribPointer(_positionLocation, 3, GL_FLOAT, GL_FALSE, sizeof(FBVertex), 0);
    glVertexAttribPointer(_colorLocation, 4, GL_FLOAT, GL_FALSE, sizeof(FBVertex), (GLvoid*) (sizeof(float) * 3));
    glVertexAttribPointer(_texCoordsLocation, 2, GL_FLOAT, GL_FALSE, sizeof(FBVertex), (GLvoid*) (sizeof(float) * 7));
    
    glDrawElements(GL_TRIANGLE_STRIP, sizeof(Indices), GL_UNSIGNED_BYTE, 0);
}

void FBSprite::setTexture(const char *fileName)
{
    delete _texture;
    FBImage *image = new FBImage(fileName);
    _texture = new FBTexture(image);
    delete image;
}

FBRect FBSprite::getBoundingBox()
{
    FBPoint position = getPosition();
    FBSize texSize = _texture->getSize();
    return {position.x - texSize.width/2, position.y - texSize.height/2, texSize.width, texSize.height};
}

FBRect FBSprite::getCollisionBox()
{
    FBPoint position = getPosition();
    FBSize texSize = _texture->getSize();
    return {position.x - texSize.width/2 * getScale(),
            position.y - texSize.height/2* getScale(),
            texSize.width* getScale(),
            texSize.height* getScale()};
}

void FBSprite::setPosition(const FBPoint &position)
{
    FBNode::setPosition(position);
}

void FBSprite::setPosition(float x, float y)
{
    FBNode::setPosition({x, y});
}

void FBSprite::setRotation(const float rotation)
{
    FBNode::setRotation(rotation);
}

void FBSprite::updatePosition()
{
    FBPoint position = {0, 0};
    
    float dx = 2.0f/_winSize.width;
    float dy = 2.0f/_winSize.height;
    
    FBSize textureSize = _texture->getSize();
    
    float x1 = (position.x + textureSize.width/2)*dx;
    float y1 = (position.y - textureSize.height/2)*dy;
    
    float x2 = (position.x + textureSize.width/2)*dx;
    float y2 = (position.y + textureSize.height/2)*dy;
    
    float x3 = (position.x - textureSize.width/2)*dx;
    float y3 = (position.y + textureSize.height/2)*dy;
    
    float x4 = (position.x - textureSize.width/2)*dx;
    float y4 = (position.y - textureSize.height/2)*dy;
    
    FBColor color = {1, 1, 1, 1};
    
    _vertices[0] = {{x1, y1, 0}, color, {1, 1}};
    _vertices[1] = {{x2, y2, 0}, color, {1, 0}};
    _vertices[2] = {{x3, y3, 0}, color, {0, 0}};
    _vertices[3] = {{x4, y4, 0}, color, {0, 1}};
}

void FBSprite::transform()
{
    if(!_needTransform)
        return;

    _needTransform = false;
    
    float posX = -1.0f + _position.x*2.0f/_winSize.width;
    float posY = -1.0f + _position.y*2.0f/_winSize.height;
    
    Matrix4f ScaleTrans, RotateTrans, TranslationTrans;
    
    ScaleTrans.InitScaleTransform(_scale, _scale, 1);
    RotateTrans.InitRotateTransformZ(_angle);
    TranslationTrans.InitTranslationTransform(posX, posY, 1);
    _transformation = TranslationTrans * ScaleTrans * RotateTrans ;
}