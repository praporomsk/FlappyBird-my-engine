//
//  FBButton.hpp
//  Flappy Bird
//
//  Created by Roman Semenov on 10/12/15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBButton_h
#define FBButton_h

#include <stdio.h>
#include "FBSprite.h"

typedef std::function<void(FBNode*)> ButtonCallback;

class FBButton : public FBSprite
{
public:
    explicit FBButton(const char *fileName);
    bool init(const ButtonCallback& callback);
    ~FBButton();
    
    void touches(const FBTouches& toches, FBTouchEventType touchType);
private:
    void onTap(FBTouchEventType touchType);
    ButtonCallback _callback;
};
#endif /* FBButton_h */
