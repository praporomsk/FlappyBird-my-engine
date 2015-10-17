//
//  FBNode.h
//  Flappy Bird
//
//  Created by Roman Semenov on 03.10.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBNode_h
#define FBNode_h

#include "FBShaderProgram.h"
#include "FBTypes.h"
#include "FBTouchDispatcher.h"

class FBNode : public FBTouchObject {
public:
    FBNode();
   
    virtual void render() {}
    virtual void update(float dt) {}
    
    virtual void setVisible(bool visble);
    virtual bool isVisible();
    
    virtual void setPosition(const FBPoint &position);
    virtual const FBPoint& getPosition();

    virtual void setRotation(const float angle);
    virtual const float getRotation();
    
    virtual void setBoundingBox(FBRect &rect);
    virtual FBRect getBoundingBox();
    
    virtual void setScale(float scale);
    virtual float getScale() {return _scale;}

    virtual void setZOrder(int zOrder);
    virtual int getZOrder() {return _zOrder;}
    
    void setShaderProgram(FBShaderType type);
    FBShaderProgram *getShaderProgram();
    
    virtual void setTouchEnabled(bool touchEnabled);
    bool isTouchEnabled();
    
    virtual void touches(const FBTouches& toches, FBTouchEventType touchType) {}
    virtual void transform() {}
protected:
    
    FBShaderProgram *_shaderProgram;

    bool _isVisble;
    FBPoint _position;
 
    FBRect _boundingBox;
    float _angle;
    float _scale;
    bool _touchEnabled;
    FBNode *_parent;
    bool _needTransform;
    int _zOrder;
};
#endif /* FBNode_hpp */
