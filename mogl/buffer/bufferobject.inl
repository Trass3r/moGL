////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file bufferobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "bufferobject.hpp"

namespace mogl
{
    inline BufferObject::BufferObject(GLenum target)
    :   _handle(0),
        _target(target)
    {
        glCreateBuffers(1, &_handle);
    }

    inline BufferObject::~BufferObject()
    {
        glDeleteBuffers(1, &_handle);
    }

    inline void BufferObject::bind()
    {
        glBindBuffer(_target, _handle);
    }

    inline void BufferObject::setData(GLsizeiptr size, const GLvoid* data, GLenum usage)
    {
        glNamedBufferData(_handle, size, data, usage);
    }

    inline GLuint BufferObject::getHandle() const
    {
        return _handle;
    }
}
