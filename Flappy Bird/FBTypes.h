//
//  FBTypes.h
//  Flappy Bird
//
//  Created by Roman Semenov on 27.09.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBTypes_h
#define FBTypes_h

#include <vector>
#include <math.h>

typedef enum
{
    SHADER_TEXTURE_AND_COLOR,
    SHADERS_COLOR,
    SHADERS_SIZE
}FBShaderType;

static const char *shaderNames[SHADERS_SIZE] = {"Texture_and_color", "Color"};

typedef enum
{
    TOUCH_EVENT_BEGAN,
    TOUCH_EVENT_MOVED,
    TOUCH_EVENT_ENDED,
    TOUCH_EVENT_CANCELED
}FBTouchEventType;

typedef struct _Point {
    float x;
    float y;
    
    inline float getAngle() const {
        return atan2f(y, x);
    };
} FBPoint;

typedef struct _Size {
    float width;
    float height;
} FBSize;

typedef struct _Rect {
    FBPoint origin;
    FBSize size;
} FBRect;

typedef struct _Range {
    float location;
    float length;
} FBRange;

typedef FBPoint FBTouch;

typedef std::vector<FBTouch> FBTouches;

typedef struct _ImageInfo {
    FBSize size;
    unsigned char *data;
} FBImageInfo;

typedef struct _Color {
    float r;
    float g;
    float b;
    float a;
} FBColor;

typedef FBPoint FBTexCoords;

typedef struct _Vertex {
    float position[3];
    FBColor color;
    FBTexCoords TexCoord;
} FBVertex;

typedef enum
{
    BACKGROUND_ZORDER,
    PIPE_ZORDER,
    GROUND_ZORDER,
    BIRD_ZORDER,
    HUD_ZORDER
}zOrderEnum;

typedef enum
{
    GAME_STATE_TUTORIAL,
    GAME_STATE_GAME,
    Game_STATE_GAMEOVER
}GameState;

#endif /* FBTypes_h */
