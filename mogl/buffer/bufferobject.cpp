////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file bufferobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "mogl/moglbuild.h"
#include "bufferobject.hpp"

namespace mogl
{
    BufferObject::BufferObject(GLenum target)
    :   _handle(0),
        _target(target)
    {
        glGenBuffers(1, &_handle);
    }

    BufferObject::~BufferObject()
    {
        glDeleteBuffers(1, &_handle);
    }

    void BufferObject::bind()
    {
        glBindBuffer(_target, _handle);
    }

    void BufferObject::setData(GLsizeiptr size, const void* data, GLenum usage)
    {
        glBufferData(_target, size, data, usage);
    }

    GLuint BufferObject::getHandle() const
    {
        return _handle;
    }
}