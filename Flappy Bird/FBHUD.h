//
//  FBHUD.hpp
//  Flappy Bird
//
//  Created by Roman Semenov on 10/11/15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBHUD_hpp
#define FBHUD_hpp

#include "FBLayer.h"
#include "FBSprite.h"
#include "HUDDelegate.h"

class FBButton;

class FBHUD : public FBLayer {
public:
    FBHUD();
    bool init();
    void setState(GameState state);
    void setDelegate(HUDDelegate* delegate);
private:
    FBSprite* _tutorial;
    FBSprite* _gameOver;
    FBButton* _playButton;
    HUDDelegate* _delegate;
};

#endif /* FBHUD_hpp */
