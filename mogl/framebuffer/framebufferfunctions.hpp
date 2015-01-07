////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebufferfunctions.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_FRAMEBUFFERFUNCTIONS_INCLUDED
#define MOGL_FRAMEBUFFERFUNCTIONS_INCLUDED

#include <mogl/renderbuffer/renderbufferobject.hpp>
#include <mogl/texture/textureobject.hpp>

namespace mogl
{
    class FrameBuffer
    {
    public:
        enum class Target {
            DrawFrameBuffer = GL_DRAW_FRAMEBUFFER,
            ReadFrameBuffer = GL_READ_FRAMEBUFFER,
            FrameBuffer = GL_FRAMEBUFFER
        };
        enum class Attachment {
            Color0 = GL_COLOR_ATTACHMENT0,
            Color1 = GL_COLOR_ATTACHMENT1,
            Color2 = GL_COLOR_ATTACHMENT2,
            Color3 = GL_COLOR_ATTACHMENT3,
            Depth = GL_DEPTH_ATTACHMENT,
            Stencil = GL_STENCIL_ATTACHMENT
        };

        static bool isComplete(Target target);
        static void setRenderBuffer(Target target, Attachment attachment, const RenderBufferObject& renderbuffer);
        static void setTexture(Target target, Attachment attachment, mogl::TextureObject& texture, GLint level = 0);
        static void setTexture1D(Target target, Attachment attachment, mogl::TextureObject& texture, GLint level = 0);
        static void setTexture2D(Target target, Attachment attachment, mogl::TextureObject& texture, GLint level = 0);
        static void setTexture3D(Target target, Attachment attachment, mogl::TextureObject& texture, GLint level = 0, GLint layer = 0);
    };
}

#include "framebufferfunctions.inl"

#endif // MOGL_FRAMEBUFFERFUNCTIONS_INCLUDED
