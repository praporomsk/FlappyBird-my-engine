//
//  FBMainScene.cpp
//  Flappy Bird
//
//  Created by Roman Semenov on 03.10.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#include "FBMainScene.h"
#include "FBHelper.h"
#include "FBHUD.h"
#include "FBBird.h"

FBMainScene::FBMainScene()
{
    FBSize winSize = getWinSize();
    float backPosX = 0;
    while (backPosX < winSize.width) {
        FBSprite* back = new FBSprite("fb_background.png");
        back->setScale(globalScale);
        back->setPosition({backPosX + back->getBoundingBox().size.width/2 * globalScale, winSize.height/2});
        addChild(back);
        backPosX += back->getBoundingBox().size.width * globalScale;
        back = NULL;
    }

    addGround();
    addPipes();

    _bird = new FBBird();
    _bird->setScale(globalScale);
    _bird->setZOrder(BIRD_ZORDER);
    addChild(_bird);
   
    _hud = new FBHUD();
    _hud->init();
    _hud->setDelegate(this);
    _hud->setZOrder(HUD_ZORDER);
    addChild(_hud);
  
    setState(GAME_STATE_TUTORIAL);
    setTouchEnabled(true);
    FBTouchDispatcher::getInstance()->addTouchObject(this);
    resetGame();
}

FBMainScene::~FBMainScene()
{
    FBTouchDispatcher::getInstance()->removeTouchObject(this);
}

void FBMainScene::addGround()
{
    float offsetX = 0;
    _grounds.reserve(kFBGroundNum);
    for (int i = 0; i < kFBGroundNum; i++) {
        FBSprite* ground = new FBSprite("ground.png");
        ground->setScale(globalScale);
        ground->setZOrder(GROUND_ZORDER);
        ground->setPosition({offsetX + ground->getBoundingBox().size.width/2 * globalScale, ground->getBoundingBox().size.height/2});
        addChild(ground);
        offsetX +=  ground->getBoundingBox().size.width * globalScale;
        _grounds.push_back(ground);
    }
    _leftGroundIter = _grounds.begin();
}

void FBMainScene::addPipes()
{
    float offsetX = kFBFirstPipePosX * globalScale;
    for (int i = 0; i < kFBPipesNum; i++) {
        
        float centerY = kFBRandomPipeYpos.location * globalScale + random(kFBRandomPipeYpos.length * globalScale);
        FBSprite* up = new FBSprite("up_pipe.png");
        up->setScale(globalScale);
        up->setZOrder(PIPE_ZORDER);
        addChild(up);
    
        FBSprite* down = new FBSprite("down_pipe.png");
        down->setScale(globalScale);
        down->setZOrder(PIPE_ZORDER);
        addChild(down);
        
        PipePair pair = {up, down};
        pair.setCenterPos({offsetX, centerY});
        _pipes.push_back(pair);
        offsetX += kFBDisBetweenPipesX * globalScale;
    }
    
    _leftPipeIter = _pipes.begin();
}

void FBMainScene::update(float dt)
{
    if (_gameState == GAME_STATE_GAME) {
        _bird->updateAnimation(dt);
        updateGround(dt);
        _bird->update(dt);
        updatePipes(dt);
        if (checkCollision())
            gameOver();
    }else if (_gameState == GAME_STATE_TUTORIAL){
        _bird->updateAnimation(dt);
        updateGround(dt);
    }else if (_gameState == Game_STATE_GAMEOVER){
        _bird->update(dt);
    }
}

void FBMainScene::resetGame()
{
    _bird->reset();
    float offsetX = kFBFirstPipePosX * globalScale;
    for (Pipes_t::iterator it = _pipes.begin(); it != _pipes.end(); it++) {
        PipePair& pair = *it;
        float centerY = kFBRandomPipeYpos.location * globalScale + random(kFBRandomPipeYpos.length * globalScale);
        pair.setCenterPos({offsetX, centerY});
        offsetX += kFBDisBetweenPipesX * globalScale;
    }
    _leftPipeIter = _pipes.begin();
}

bool FBMainScene::checkCollision()
{
    for (auto it = _pipes.begin(); it != _pipes.end(); ++it) {
        PipePair& piar = *it;
        
        if (intersectsRectAndCircle(piar.upPipe->getCollisionBox(), _bird->getPosition(), _bird->getCollisionBox().size.height/2))
            return true;
        
        if (intersectsRectAndCircle(piar.downPipe->getCollisionBox(), _bird->getPosition(), _bird->getCollisionBox().size.height/2))
            return true;
    }
    
    if (_bird->getPosition().y - _bird->getCollisionBox().size.height/2 < (*_leftGroundIter)->getCollisionBox().size.height/2)
        return true;
    
    if (_bird->getPosition().y + _bird->getCollisionBox().size.height/2 >= getWinSize().height)
        return true;
    
    return false;
}

void FBMainScene::updatePipes(float dt)
{
    const float speed = _bird->getVelocity().x;
    
    for (auto it = _pipes.begin(); it != _pipes.end(); ++it) {
        PipePair& piar = *it;
        float posX = piar.upPipe->getPosition().x - speed * dt;
        piar.upPipe->setPosition(posX, piar.upPipe->getPosition().y);
        piar.downPipe->setPosition(posX, piar.downPipe->getPosition().y);
    }
    
    PipePair& pair = *_leftPipeIter;
    if (pair.upPipe->getPosition().x < -pair.upPipe->getBoundingBox().size.width/2 * globalScale) {
        Pipes_t::iterator maxPosIterator = _leftPipeIter == _pipes.begin() ? _pipes.end() - 1 : _leftPipeIter - 1;
        float maxPosX = (*maxPosIterator).upPipe->getPosition().x;
        maxPosX += kFBDisBetweenPipesX * globalScale;
        
        float centerY = kFBRandomPipeYpos.location * globalScale + random(kFBRandomPipeYpos.length * globalScale);
        pair.setCenterPos({maxPosX, centerY});
        _leftPipeIter++;
        if (_leftPipeIter == _pipes.end())
            _leftPipeIter = _pipes.begin();
    }
}

void FBMainScene::updateGround(float dt)
{
    const float speed = _bird->getVelocity().x;
    for (auto it = _grounds.begin(); it != _grounds.end(); ++it) {
        FBSprite* g = *it;
        float posX = g->getPosition().x - speed * dt;
        g->setPosition(posX, g->getPosition().y);
    }
    
    FBSprite* leftGround = *_leftGroundIter;
    if (leftGround->getPosition().x < -leftGround->getBoundingBox().size.width/2 * globalScale) {
        Grounds_t::iterator maxPosIterator = _leftGroundIter == _grounds.begin() ? _grounds.end() - 1 : _leftGroundIter - 1;
        float maxPosX = (*maxPosIterator)->getPosition().x;
        
        leftGround->setPosition(maxPosX + leftGround->getBoundingBox().size.width * globalScale, leftGround->getPosition().y);
        _leftGroundIter++;
        if (_leftGroundIter == _grounds.end())
            _leftGroundIter = _grounds.begin();
    }
}

void FBMainScene::setState(GameState state)
{
    _hud->setState(state);
    _gameState = state;
}

void FBMainScene::gameOver()
{
    _bird->fall();
    setState(Game_STATE_GAMEOVER);
}

void FBMainScene::touches(const FBTouches& toches, FBTouchEventType touchType)
{
    if (touchType != TOUCH_EVENT_BEGAN)
        return;
    
    if (_gameState == GAME_STATE_TUTORIAL)
        setState(GAME_STATE_GAME);
    
    _bird->tapUp();
}

void FBMainScene::onPlay()
{
    setState(GAME_STATE_TUTORIAL);
    resetGame();
}

