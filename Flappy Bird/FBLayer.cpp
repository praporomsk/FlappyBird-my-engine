//
//  FBLayer.cpp
//  Flappy Bird
//
//  Created by Roman Semenov on 03.10.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#include "FBLayer.h"

using namespace std;

FBLayer::~FBLayer()
{
    vector<FBNode *>::iterator it = _childs.begin();
    for (; it != _childs.end(); ++it) {
        FBNode *node = (*it);
        delete node;
    }
    
    _childs.clear();
}

void FBLayer::addChild(FBNode *object)
{
    _childs.push_back(object);
    std::sort(_childs.begin(), _childs.end(),
              [] (FBNode* a, FBNode* b) { return a->getZOrder() < b->getZOrder(); });
}

void FBLayer::render()
{
    std::for_each(_childs.begin(), _childs.end(), [](FBNode* n){ n->render(); });
}

void FBLayer::update(float dt)
{
    vector<FBNode *>::iterator it = _childs.begin();
    for (; it != _childs.end(); ++it)
        (*it)->update(dt);
}

void FBLayer::transform()
{
    std::for_each(_childs.begin(), _childs.end(), [](FBNode* n){ n->transform(); });
}

