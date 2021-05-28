#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <GL/glew.h>
#include <memory>
#include "Buffer.h"

class VertexBuffer : public Buffer {
    public:
        virtual ~VertexBuffer ();
        static std::shared_ptr<VertexBuffer> Create (float* vertices, uint32_t size);
};

#endif