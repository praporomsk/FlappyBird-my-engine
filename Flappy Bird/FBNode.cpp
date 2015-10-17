//
//  FBNode.cpp
//  Flappy Bird
//
//  Created by Roman Semenov on 03.10.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#include "FBNode.h"
#include "FBShadersCache.h"

using namespace std;

FBNode::FBNode() :
_angle(0.0f),
_position (FBPoint{0, 0}),
_isVisble (true),
_touchEnabled (false),
_scale (1.0f),
_needTransform (false),
_zOrder(0),
_shaderProgram(nullptr)
{

}

void FBNode::setVisible(bool visble)
{
    _isVisble = visble;
}

bool FBNode::isVisible()
{
    return _isVisble;
}

void FBNode::setPosition(const FBPoint &position)
{
    _position = position;
    _needTransform = true;
}

const FBPoint& FBNode::getPosition()
{
    return _position;
}

void FBNode::setRotation(const float angle)
{
    _angle = angle;
    _needTransform = true;
}

const float FBNode::getRotation()
{
    return _angle;
}

void FBNode::setTouchEnabled(bool touchEnabled)
{
    _touchEnabled = touchEnabled;
}

bool FBNode::isTouchEnabled()
{
    return _touchEnabled;
}

void FBNode::setShaderProgram(FBShaderType type)
{
    _shaderProgram = FBShadersCache::getInstance()->getProgram(type);
}

void FBNode::setBoundingBox(FBRect &rect)
{
    _boundingBox = rect;
}

FBRect FBNode::getBoundingBox()
{
    return _boundingBox;
}

void FBNode::setScale(float scale)
{
    _scale = scale;
    _needTransform = true;
}

FBShaderProgram *FBNode::getShaderProgram()
{
    return _shaderProgram;
}

void FBNode::setZOrder(int zOrder)
{
    _zOrder = zOrder;
}

