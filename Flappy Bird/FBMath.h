//
//  math_3d.h
//  Flappy Bird
//
//  Created by Roman Semenov on 03.10.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef MATH_3D_H
#define	MATH_3D_H

#include <stdio.h>
#include <math.h>

class Matrix4f
{
public:
    float m[16];

    Matrix4f()
    {        
    }

    inline void InitIdentity()
    {
        m[0] = 1.0f; m[1] = 0.0f; m[2] = 0.0f; m[3] = 0.0f;
        m[4] = 0.0f; m[5] = 1.0f; m[6] = 0.0f; m[7] = 0.0f;
        m[8] = 0.0f; m[9] = 0.0f; m[10] = 1.0f; m[11] = 0.0f;
        m[12] = 0.0f; m[13] = 0.0f; m[14] = 0.0f; m[15] = 1.0f;
    }

    inline int at(int i, int j)
    {
        return i + (j * 4);
    }
    
    inline Matrix4f operator*(const Matrix4f& Right) const
    {
        Matrix4f Ret;

        for (unsigned int i = 0 ; i < 4 ; i++) {
            for (unsigned int j = 0 ; j < 4 ; j++) {
                Ret.m[Ret.at(i,j)] =
                m[Ret.at(i,0)] * Right.m[Ret.at(0,j)] +
                m[Ret.at(i,1)] * Right.m[Ret.at(1,j)] +
                m[Ret.at(i,2)] * Right.m[Ret.at(2,j)] +
                m[Ret.at(i,3)] * Right.m[Ret.at(3,j)];
                
            }
        }

        return Ret;
    }

    void InitScaleTransform(float ScaleX, float ScaleY, float ScaleZ);
    void InitRotateTransform(float RotateX, float RotateY, float RotateZ);
    void InitRotateTransformZ(float RotateZ);
    void InitTranslationTransform(float x, float y, float z);

};

#endif	/* MATH_3D_H */

