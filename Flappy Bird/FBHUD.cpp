//
//  FBHUD.cpp
//  Flappy Bird
//
//  Created by Roman Semenov on 10/11/15.
//  Copyright © 2015 Roman. All rights reserved.
//

#include "FBHUD.h"
#include "FBHelper.h"
#include "FBConstants.h"
#include "FBButton.h"

FBHUD::FBHUD()
:_delegate (nullptr)
,_tutorial(nullptr)
,_gameOver(nullptr)
,_playButton(nullptr)
{

}

bool FBHUD::init()
{
    FBSize winSize = getWinSize();
    _tutorial = new FBSprite("tutorial.png");
    _tutorial->setPosition({winSize.width/2,winSize.height/2});
    _tutorial->setScale(globalScale);
    addChild(_tutorial);
    
    _gameOver = new FBSprite("game_over.png");
    _gameOver->setPosition({winSize.width/2,winSize.height/2});
    _gameOver->setScale(globalScale);
    addChild(_gameOver);
    
    _playButton = new FBButton("play_button.png");
    _playButton->init([&](FBNode *sender){
        if (_delegate)
            _delegate->onPlay();
    });
    _playButton->setPosition({winSize.width/2,winSize.height * 0.3f});
    _playButton->setScale(globalScale);
    addChild(_playButton);
    
    return true;
}

void FBHUD::setDelegate(HUDDelegate* delegate)
{
    _delegate = delegate;
}

void FBHUD::setState(GameState state)
{
    switch (state) {
        case GAME_STATE_TUTORIAL:
            _tutorial->setVisible(true);
            _gameOver->setVisible(false);
            _playButton->setVisible(false);
            _playButton->setTouchEnabled(false);
            break;
            
        case GAME_STATE_GAME:
            _tutorial->setVisible(false);
            
            break;
        case Game_STATE_GAMEOVER:
            _gameOver->setVisible(true);
            _playButton->setVisible(true);
            _playButton->setTouchEnabled(true);
        default:
            break;
    }
}
