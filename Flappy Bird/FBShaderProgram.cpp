//
//  FBShaderProgram.cpp
//  Flappy Bird
//
//  Created by Roman Semenov on 27.09.15.
//  Copyright © 2015 Roman. All rights reserved.
//

#include "FBShaderProgram.h"
#include "FBHelper.h"

FBShaderProgram::FBShaderProgram(const char *shaderName)
{
    std::string vertexName = std::string(shaderName) + std::string(".vsh");
    _vertexBuffer = dataFromFile(vertexName.c_str());
    
    std::string fragmentName = std::string(shaderName) + std::string(".fsh");
    _fragmentBuffer = dataFromFile(fragmentName.c_str());
    
    if (!_vertexBuffer || !_fragmentBuffer) {
         printf("Error! Couldn't read shader files!\n");
        return;
    }
 
    _vertexShader = compileShader(GL_VERTEX_SHADER, (GLchar *)_vertexBuffer);
    _fragmentShader = compileShader(GL_FRAGMENT_SHADER, (GLchar *)_fragmentBuffer);
    
    _program = glCreateProgram();
    
    if (_vertexShader != -1 && _fragmentShader != -1) {
        glAttachShader(_program, _vertexShader);
        glAttachShader(_program, _fragmentShader);
        linkShader();
    }
    else {
        printf("Error! While compiling shaders\n");
    }
}

void FBShaderProgram::use()
{
    glUseProgram(_program);
}

GLuint FBShaderProgram::compileShader(GLenum type, const GLchar *source)
{
    std::string tmpStr = std::string((const char *)source);
    const GLint len = tmpStr.length();
    GLint status = -1;
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, &len);
    glCompileShader(shader);
    
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    
    if (status == GL_FALSE)
    {
        GLchar messages[256];
        glGetShaderInfoLog(shader, sizeof(messages), 0, &messages[0]);
        printf("Shader compiling %s", messages);
        exit(1);
    }
    else
        return shader;
}

GLuint FBShaderProgram::getProgram()
{
    return _program;
}

void FBShaderProgram::linkShader()
{
    glLinkProgram(_program);
    
    GLint linkSuccess;
    glGetProgramiv(_program, GL_LINK_STATUS, &linkSuccess);
    if (linkSuccess == GL_FALSE) {
        GLchar messages[256];
        glGetProgramInfoLog(_program, sizeof(messages), 0, &messages[0]);
        printf("Link shader %s", messages);
        exit(1);
    }
}