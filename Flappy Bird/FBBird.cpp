//
//  FBBird.c
//  Flappy Bird
//
//  Created by Roman Semenov on 10/8/15.
//  Copyright © 2015 Roman. All rights reserved.
//

#include "FBBird.h"
#include "FBHelper.h"
#include "FBConstants.h"

FBBird::FBBird() : FBSprite("bird_0.png")
,_velocity ({kFBBirdSpeed * globalScale, 0})
,_secPerFrame(0.166666667f)
,_timer(0)
,_isFalling(false)
{
    char buff[32];
    _animationFrames.reserve(3);
    _animationFrames.push_back(_texture);
    for (int i = 1; i < 3; i++) {
        sprintf(buff, "bird_%d.png",i);
        FBImage *image = new FBImage(buff);
        FBTexture* texture = new FBTexture(image);
        delete image;
        _animationFrames.push_back(texture);
    }
    _animationFrames.push_back(_animationFrames[1]);
    _currentFrame = _animationFrames.begin();
}

FBBird::~FBBird()
{
    std::vector<FBTexture *>::iterator it = _animationFrames.begin();
    for (; it != _animationFrames.end(); ++it) {
        if (it == _animationFrames.end() -1)
            break;
        
        if (it == _currentFrame)
            continue;

        FBTexture *tex = (*it);
        delete tex;
    }
}

void FBBird::updateAnimation(float dt)
{
    _timer += dt;
    if (_timer > _secPerFrame) {
        _timer -= _secPerFrame;
        _currentFrame++;
        if (_currentFrame == _animationFrames.end())
            _currentFrame = _animationFrames.begin();
        
        _texture = *_currentFrame;
    }
}

void FBBird::reset()
{
    FBSize winSize = getWinSize();
    _isFalling = false;
    setPosition({winSize.width * 0.3f, winSize.height/2});
    setRotation(0);
}

void FBBird::update(float dt)
{
    FBSprite::update(dt);

    const FBPoint& pos = getPosition();
    setPosition({pos.x, pos.y + _velocity.y});
    
    _velocity.y -= kFBGravity * getScale() * dt;

    if (!_isFalling)
        setRotation(-RADIANS_TO_DEGREES(_velocity.getAngle() * 4));
}

void FBBird::setPosition(const FBPoint &position)
{
    FBSprite::setPosition({position.x, fminf(position.y, getWinSize().height)});
}

void FBBird::tapUp()
{
    if (_isFalling)
        return;
    
    _velocity = {kFBBirdSpeed * globalScale, kFBTapVelocityY * globalScale};
}

void FBBird::fall()
{
    _isFalling = true;
    _velocity = {kFBBirdSpeed * globalScale, 0};
}

