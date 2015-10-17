//
//  FBHelper_ios.m
//  Flappy Bird
//
//  Created by Roman Semenov on 27.09.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#include "FBHelper_ios.h"
#import <UIKit/UIKit.h>

FBSize getWinSizeIOS()
{
    CGRect screenBounds = [[UIScreen mainScreen] bounds];
    float scale = [[UIScreen mainScreen] scale];
    
    CGRect myBounds = CGRectMake(screenBounds.origin.x, screenBounds.origin.y,
                                 screenBounds.size.width*scale, screenBounds.size.height*scale);
    
    FBSize size = {(float)myBounds.size.width, (float)myBounds.size.height};
    return size;
}

FBImageInfo getImageDataIOS(const char *filePath)
{
    NSString *fullPath = [NSString stringWithUTF8String:filePath];
    
    CGImageRef imageRef = [UIImage imageNamed:fullPath].CGImage;
    assert(imageRef); //image not found
    
    size_t width = CGImageGetWidth(imageRef);
    size_t height = CGImageGetHeight(imageRef);
    
    unsigned char* imageData = (unsigned char*)malloc(sizeof(unsigned char) * (int)(width * height * 4));
    memset(imageData, 0, (int)(width * height * 4));
    
    CGContextRef spriteContext = CGBitmapContextCreate(imageData, width, height, 8, width*4,
                                                       CGImageGetColorSpace(imageRef), kCGImageAlphaPremultipliedLast);
    
    CGContextDrawImage(spriteContext, CGRectMake(0, 0, width, height), imageRef);
    CGContextRelease(spriteContext);
    
    FBSize size = {(float)width , (float)height};
    FBImageInfo info = {size, imageData};
    return info;
}

const char* getFullPathIOS(const char *fileName)
{
    NSString* nsFileName = [NSString stringWithCString:fileName encoding:NSUTF8StringEncoding];
    NSString* fullpath = [[NSBundle mainBundle] pathForResource:nsFileName
                                                         ofType:nil];
    if (!fullpath)
        return NULL;
    
    return [fullpath UTF8String];
}