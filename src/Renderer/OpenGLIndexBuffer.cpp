#include "Renderer/OpenGLIndexBuffer.h"
#include <GL/glew.h>

OpenGLIndexBuffer::OpenGLIndexBuffer (uint32_t* indices, uint32_t count) : _count{count} {
    glCreateBuffers (1, &_buffer_id);
    glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, _buffer_id);
    glBufferData (GL_ELEMENT_ARRAY_BUFFER, count * sizeof (uint32_t), indices, GL_STATIC_DRAW);
}

OpenGLIndexBuffer::~OpenGLIndexBuffer  () {
    glDeleteBuffers (1, &_buffer_id);
}

void OpenGLIndexBuffer::bind () const {
    glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, _buffer_id);
}

void OpenGLIndexBuffer::unbind () const {
    glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, 0);
}

uint32_t OpenGLIndexBuffer::getCount () const {
    return _count;
}