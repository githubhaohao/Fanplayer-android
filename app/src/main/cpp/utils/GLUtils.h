//
// Created by 微信公众号：字节流动 on 2019/12/3.
//

#ifndef APK_GLUTILS_H
#define APK_GLUTILS_H

#include <GLES3/gl3.h>
#include <stdlib.h>
#include "LogUtil.h"

#define SHADER_TO_STRING(s) #s

static const char kDefaultFragmentShader[] = SHADER_TO_STRING(
        //#version 100
        varying vec2 v_texcoord;
        attribute vec4 position;
        attribute vec2 texcoord;
        uniform mat4 MVP;
        void main() {
        v_texcoord = texcoord;
        gl_Position = MVP*position;
        }
);

//For PI define
#define MATH_PI 3.1415926535897932384626433832802

static const char DefaultVertexShader[] =
        "#version 100\n"
        "varying vec2 v_texcoord;\n"
        "attribute vec4 position;\n"
        "attribute vec2 texcoord;\n"
        "uniform mat4 MVP;\n"
        "void main() {\n"
        "    v_texcoord = texcoord;\n"
        "    gl_Position = MVP*position;\n"
        "}";

static const char DefaultFragmentShader[] =
        "#version 100\n \
        precision highp float; \
        varying vec2 v_texcoord;\
        uniform lowp sampler2D s_texture;\
        void main() {\
            gl_FragColor = texture2D(s_texture, v_texcoord);\
        }";

static const float VERTICES_COORS[] =
        {
                -1.f, 1.f,
                -1.f, -1.f,
                1.f, 1.f,
                1.f, -1.f
        };

static const float TEXTURE_COORS[] =
        {
                0, 0,
                0, 1,
                1, 0,
                1, 1
        };

#ifdef __cplusplus
extern "C" {
#endif

void CheckGLError(const char *pGLOperation);

GLuint LoadShader(GLenum shaderType, const char *pSource);

GLuint CreateProgram(const char *pVertexShaderSource, const char *pFragShaderSource, GLuint &vertexShaderHandle, GLuint &fragShaderHandle);

void DeleteProgram(GLuint &program);

#ifdef __cplusplus
}
#endif

#endif //APK_GLUTILS_H
