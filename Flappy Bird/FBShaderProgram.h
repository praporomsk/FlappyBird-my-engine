//
//  FBShaderProgram.hpp
//  Flappy Bird
//
//  Created by Roman Semenov on 27.09.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#ifndef FBShaderProgram_h
#define FBShaderProgram_h

#include <iostream>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#define kShaderTextureAndColor "Texture_and_color"
#define kShaderColor           "Color"

#define kShaderMVUniform        "modelView"
#define kShaderProjectUniform   "projection"
#define kShaderTextureUniform   "texture"

#define kShaderPositionAttr     "position"
#define kShaderTextureAttr      "texCoordIn"
#define kShaderColorAttr        "colorIn"

class FBShaderProgram {
public:
    explicit FBShaderProgram(const char *shaderName);
    void linkShader();
    void updateUniforms();
    void use();
    void setBuiltinUniforms();
    GLuint getProgram();
    
private:
    GLuint compileShader(GLenum type, const GLchar *source);
    
    unsigned char *_vertexBuffer;
    unsigned char *_fragmentBuffer;
    
    GLuint _vertexShader;
    GLuint _fragmentShader;
    GLuint _program;
};
#endif /* FBShaderProgram_h */
