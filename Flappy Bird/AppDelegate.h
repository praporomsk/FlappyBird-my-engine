//
//  AppDelegate.h
//  Flappy Bird
//
//  Created by Roman Semenov on 27.09.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GLViewController.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>
{
    GLViewController *_glViewController;
}
@property (strong, nonatomic) UIWindow *window;
@property (nonatomic, retain) IBOutlet GLViewController *glViewController;

@end

