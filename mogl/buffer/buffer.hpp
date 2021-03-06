////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file buffer.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
///
/// @brief Buffer object OO wrapper using OpenGL 4.5 DSA features
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_BUFFER_INCLUDED
#define MOGL_BUFFER_INCLUDED

#include <mogl/handle.hpp>

namespace mogl
{
    class Buffer : public Handle<GLuint>
    {
    public:
        Buffer(GLenum target);
        ~Buffer();

        Buffer(const Buffer& other) = delete;
        Buffer& operator=(const Buffer& other) = delete;

//      Buffer(Buffer&& other) = default;

    public:
        void    bind();
        void    setStorage(GLsizeiptr size, const void* data, GLbitfield flags);
        void    setData(GLsizeiptr size, const void* data, GLenum usage);
        void    setSubData(GLintptr offset, GLsizeiptr size, const void* data);
        void    copySubData(GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
        void    clearData(GLenum internalformat, GLenum format, GLenum type, const void* data);
        void    clearSubData(GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
        void*   map(GLenum access);
        void*   mapRange(GLintptr offset, GLsizeiptr length, GLbitfield access);
        bool    unmap();
        void    flushMappedRange(GLintptr offset, GLsizeiptr length);
        template <class T> void get(GLenum property, T* value); // Direct call to glGetNamedBufferParameter*v()
        template <class T> T    get(GLenum property);
        void    getPointerv(GLenum property, void** value);
        void    getSubData(GLintptr offset, GLsizeiptr size, void* data);
        GLenum  getTarget() const;
        bool    isValid() const override final;

    private:
        const GLenum    _target;
    };
}

#include "buffer.inl"

#endif // MOGL_BUFFER_INCLUDED
