//
//  FBBird.h
//  Flappy Bird
//
//  Created by Roman Semenov on 10/8/15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBBird_h
#define FBBird_h

#include "FBSprite.h"

typedef std::vector<FBTexture*> Frames_t;
class FBBird : public FBSprite
{
public:
    FBBird();
    ~FBBird();
    void update(float dt);
    void updateAnimation(float dt);
    void reset();
    void tapUp();
    void fall();
    const FBPoint& getVelocity() {return _velocity;}
    void setPosition(const FBPoint &position);
private:
    bool _isFalling;
    Frames_t _animationFrames;
    Frames_t::iterator _currentFrame;
    float _secPerFrame;
    float _timer;
    FBPoint _velocity;
};

#endif /* FBBird_hpp */
