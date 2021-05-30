#include "Renderer/OpenGLVertexBuffer.h"
#include <GL/glew.h>

OpenGLVertexBuffer::OpenGLVertexBuffer (float* vertices, uint32_t size) {
    glGenBuffers (1, &_buffer_id);
    glBindBuffer (GL_ARRAY_BUFFER, _buffer_id);
    glBufferData (GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer () {
    glDeleteBuffers (1, &_buffer_id);
}

auto OpenGLVertexBuffer::bind () const -> void {
    glBindBuffer (GL_ARRAY_BUFFER, _buffer_id);
}

auto OpenGLVertexBuffer::unbind () const -> void {
    glBindBuffer (GL_ARRAY_BUFFER, 0);
}