//
//  FBLayer.hpp
//  Flappy Bird
//
//  Created by Roman Semenov on 03.10.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBLayer_h
#define FBLayer_h

#include <iostream>
#include "FBNode.h"

class FBLayer : public FBNode {
public:
    virtual ~FBLayer();
    
    void addChild(FBNode *object);
    virtual void render();
    virtual void update(float dt);
    virtual void transform();
protected:
    std::vector<FBNode *> _childs;
};
#endif /* FBLayer_h */
