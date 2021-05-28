#ifndef OPENGL_VERTEX_BUFFER_H
#define OPENGL_VERTEX_BUFFER_H

#include <GL/glew.h>
#include <memory>
#include "VertexBuffer.h"

class OpenGLVertexBuffer : public VertexBuffer {
    public:
        OpenGLVertexBuffer (float* vertices, uint32_t size);
        virtual ~OpenGLVertexBuffer ();
        virtual void bind () const override;
        virtual void unbind () const override;
    
    private:
        uint32_t _buffer_id;
};

#endif