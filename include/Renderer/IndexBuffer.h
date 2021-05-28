#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

#include <GL/glew.h>
#include <memory>
#include "Buffer.h"

class IndexBuffer : public Buffer {
    public:
        virtual ~IndexBuffer ();

        /*!
         * @brief Gets index buffer count
         *
         * @return Index buffer count
         */
        virtual uint32_t getCount () const = 0;

        /*!
         * @brief Creates an index buffer using current Rendering API
         *
         * @param indices Indices used for creating buffer
         * @param count Number of buffer indices to be created 
         * @return Created buffer
         */
        static std::shared_ptr<IndexBuffer> Create (uint32_t* indices, uint32_t count);
};

#endif