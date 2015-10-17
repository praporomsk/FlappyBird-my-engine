//
//  FBHelper.cpp
//  Flappy Bird
//
//  Created by Roman Semenov on 27.09.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#include "FBHelper.h"
#include "FBHelper_ios.h"

FBSize getWinSize()
{
    return getWinSizeIOS();
}

const char* getFullPath(const char *fileName)
{
    return getFullPathIOS(fileName);
}

unsigned char* dataFromFile(const char* fileName)
{
    unsigned long size = 0;
    unsigned char *buffer;
    
    fileName = getFullPath(fileName);
    
    FILE *fd = fopen(fileName, "rb");
    if (!fd) {
        printf("Error opening file: %s\n", fileName);
        return NULL;
    }
    
    fseek(fd, 0, SEEK_END);
    size = ftell(fd);
    fseek(fd, 0, SEEK_SET);
    
    buffer = new unsigned char[size + 1];
    fread(buffer, sizeof(unsigned char), size, fd);
    fclose(fd);
    
    buffer[size] = '\0';
    return buffer; 
}

bool intersectsRectAndCircle(const FBRect& rect, const FBPoint &center, float radius)
{
    FBPoint rectangleCenter{(rect.origin.x + rect.size.width / 2),
        (rect.origin.y + rect.size.height / 2)};
    
    float w = rect.size.width / 2;
    float h = rect.size.height / 2;
    
    float dx = fabs(center.x - rectangleCenter.x);
    float dy = fabs(center.y - rectangleCenter.y);
    
    if (dx > (radius + w) || dy > (radius + h))
    {
        return false;
    }
    
    FBPoint circleDistance{fabsf(center.x - rect.origin.x - w),
        fabsf(center.y - rect.origin.y - h)};
    
    if (circleDistance.x <= (w))
        return true;
    
    if (circleDistance.y <= (h))
        return true;
    
    float cornerDistanceSq = powf(circleDistance.x - w, 2) + powf(circleDistance.y - h, 2);
    
    return (cornerDistanceSq <= (powf(radius, 2)));
}

bool rectContainsPoint(const FBRect& rect, const FBPoint& point)
{
    bool bRet = false;
    
    if (point.x >= rect.origin.x && point.x <= rect.origin.x + rect.size.width
        && point.y >= rect.origin.y && point.y <= rect.origin.y + rect.size.height)
    {
        bRet = true;
    }
    
    return bRet;
}