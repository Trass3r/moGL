////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file buffer_object.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h" // For IDE completion only

class BufferObjectTest : public GLTestFixture {};

using mogl::BufferObject;

BufferObject    createVbo()
{
    BufferObject    vbo(GL_ARRAY_BUFFER);
    std::size_t     size = 3 * 4;
    float           buffer[size];

    vbo.setData(sizeof(buffer[0]) * size, buffer, GL_STATIC_DRAW);
    EXPECT_TRUE(vbo.isValid());
    return vbo;
}

TEST_F(BufferObjectTest, vbo)
{
    BufferObject    vbo(createVbo()); // Use move semantics

    EXPECT_TRUE(vbo.isValid());
}