//
//  GLViewController.m
//  Flappy Bird
//
//  Created by Roman Semenov on 27.09.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#import "GLViewController.h"
#import "GLView.h"

@interface GLViewController ()

@end

@implementation GLViewController

-(void)loadView
{
    CGRect screenBounds = [[UIScreen mainScreen] bounds];
    float scale = [[UIScreen mainScreen] scale];
    
    CGRect myBounds = CGRectMake(screenBounds.origin.x, screenBounds.origin.y,
                                 screenBounds.size.width*scale, screenBounds.size.height*scale);
    
    GLView *glView = [[GLView alloc] initWithFrame:myBounds];
    [glView setMultipleTouchEnabled:YES];
    [glView setContentScaleFactor:scale];
    self.view = glView;
    
    [glView release];
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    return UIInterfaceOrientationIsPortrait(interfaceOrientation);
}

@end
