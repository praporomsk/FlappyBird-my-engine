#include "FBMath.h"
#include "FBHelper.h"

void Matrix4f::InitScaleTransform(float ScaleX, float ScaleY, float ScaleZ)
{
    InitIdentity();
    
    m[0] = ScaleX;
    m[5] = ScaleY;
    m[10] = ScaleZ;
}

void Matrix4f::InitRotateTransform(float RotateX, float RotateY, float RotateZ)
{
    Matrix4f rx, ry, rz;

    const float x = DEGREES_TO_RADIANS(RotateX);
    const float y = DEGREES_TO_RADIANS(RotateY);
    const float z = DEGREES_TO_RADIANS(RotateZ);

    rx.m[0] = 1.0f; rx.m[1] = 0.0f   ; rx.m[2] = 0.0f    ; rx.m[3] = 0.0f;
    rx.m[4] = 0.0f; rx.m[5] = cosf(x); rx.m[6] = -sinf(x); rx.m[7] = 0.0f;
    rx.m[8] = 0.0f; rx.m[9] = sinf(x); rx.m[10] = cosf(x) ; rx.m[11] = 0.0f;
    rx.m[12] = 0.0f; rx.m[13] = 0.0f   ; rx.m[14] = 0.0f    ; rx.m[15] = 1.0f;

    ry.m[0] = cosf(y); ry.m[1] = 0.0f; ry.m[2] = -sinf(y); ry.m[3] = 0.0f;
    ry.m[4] = 0.0f   ; ry.m[5] = 1.0f; ry.m[6] = 0.0f    ; ry.m[7] = 0.0f;
    ry.m[8] = sinf(y); ry.m[9] = 0.0f; ry.m[10] = cosf(y) ; ry.m[11] = 0.0f;
    ry.m[12] = 0.0f   ; ry.m[13] = 0.0f; ry.m[14] = 0.0f    ; ry.m[15] = 1.0f;

    rz.m[0] = cosf(z); rz.m[1] = -sinf(z); rz.m[2] = 0.0f; rz.m[3] = 0.0f;
    rz.m[4] = sinf(z); rz.m[5] = cosf(z) ; rz.m[6] = 0.0f; rz.m[7] = 0.0f;
    rz.m[8] = 0.0f   ; rz.m[9] = 0.0f    ; rz.m[10] = 1.0f; rz.m[11] = 0.0f;
    rz.m[12] = 0.0f   ; rz.m[13] = 0.0f    ; rz.m[14] = 0.0f; rz.m[15] = 1.0f;

    *this = rz * ry * rx;
}

void Matrix4f::InitRotateTransformZ(float RotateZ)
{
    const float z = DEGREES_TO_RADIANS(RotateZ);
    InitIdentity();
    m[0] = cosf(z); m[1] = -sinf(z);
    m[4] = sinf(z); m[5] = cosf(z) ;
}

void Matrix4f::InitTranslationTransform(float x, float y, float z)
{
    InitIdentity();

    m[12] = x; m[13] = y; m[14] = z;
}


