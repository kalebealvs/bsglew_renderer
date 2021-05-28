#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

#include <GL/glew.h>
#include <memory>
#include "Buffer.h"

class IndexBuffer : public Buffer {
    public:
        virtual ~IndexBuffer ();
        virtual uint32_t getCount () const = 0;
        static std::shared_ptr<IndexBuffer> Create (uint32_t* indices, uint32_t size);
};

#endif