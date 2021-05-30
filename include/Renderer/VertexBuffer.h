#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <GL/glew.h>
#include <memory>
#include "Buffer.h"

class VertexBuffer : public Buffer {
    public:
        virtual ~VertexBuffer () = 0;

        /*!
         * @brief Creates a vertex buffer using current Rendering API
         *
         * @param vertices Vertices used for creating buffer
         * @param size Size in bytes of the whole buffer 
         * @return Created buffer
         */
        static auto Create (float* vertices, uint32_t size) -> std::shared_ptr<VertexBuffer>;
};

#endif