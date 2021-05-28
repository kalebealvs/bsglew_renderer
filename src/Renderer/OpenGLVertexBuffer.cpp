#include "Renderer/OpenGLVertexBuffer.h"
#include <GL/glew.h>

OpenGLVertexBuffer::OpenGLVertexBuffer (float* vertices, uint32_t size) {
    glGenBuffers (1, &_buffer_id);
    glBindBuffer (GL_ARRAY_BUFFER, _buffer_id);
    glBufferData (GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer  () {
    glDeleteBuffers (1, &_buffer_id);
}

void OpenGLVertexBuffer::bind () const {
    glBindBuffer (GL_ARRAY_BUFFER, _buffer_id);
}

void OpenGLVertexBuffer::unbind () const {
    glBindBuffer (GL_ARRAY_BUFFER, 0);
}