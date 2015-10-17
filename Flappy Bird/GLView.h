//
//  GLView.h
//  Flappy Bird
//
//  Created by Roman Semenov on 27.09.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef GLView_h
#define GLView_h

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#include "FBMainScene.h"

@interface GLView : UIView
{
    CAEAGLLayer *_glLayer;
    EAGLContext *_context;
    GLuint _colorRenderBuffer;
    GLuint _depthRenderBuffer;
    
    FBMainScene *scene;
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
-(void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;
-(void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;

@end
#endif /* GLView_h */
