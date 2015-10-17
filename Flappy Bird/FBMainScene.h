//
//  FBMainScene.hpp
//  Flappy Bird
//
//  Created by Roman Semenov on 03.10.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBMainScene_h
#define FBMainScene_h

#include "FBSprite.h"
#include "FBLayer.h"
#include "FBConstants.h"
#include "HUDDelegate.h"

class FBHUD;
class FBBird;

typedef struct _PipePair {
    FBSprite* upPipe;
    FBSprite* downPipe;
    
    void setCenterPos(const FBPoint& pos)
    {
        upPipe->setPosition(pos.x, pos.y + kFBDisBetweenPipesY/2 * globalScale + upPipe->getCollisionBox().size.height/2);
        downPipe->setPosition(pos.x, pos.y - kFBDisBetweenPipesY/2 * globalScale - downPipe->getCollisionBox().size.height/2);
    }
 
} PipePair;

typedef std::vector<FBSprite*> Grounds_t;
typedef std::vector<PipePair> Pipes_t;

class FBMainScene : public FBLayer, public HUDDelegate{
public:
    FBMainScene();
    ~FBMainScene();
    virtual void touches(const FBTouches& toches, FBTouchEventType touchType);
    void gameOver();
    void onPlay();
    void update(float dt);
private:
    void addGround();
    void updateGround(float dt);
    void addPipes();
    void updatePipes(float dt);
    void setState(GameState state);
    void resetGame();
    bool checkCollision();
    
    Grounds_t _grounds;
    Grounds_t::iterator _leftGroundIter;
    Pipes_t _pipes;
    Pipes_t::iterator _leftPipeIter;
    FBBird* _bird;
    FBHUD* _hud;
    GameState _gameState;
};

#endif /* FBMainScene_h */
