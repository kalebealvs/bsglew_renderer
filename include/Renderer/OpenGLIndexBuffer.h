#ifndef OPENGL_INDEX_BUFFER
#define OPENGL_INDEX_BUFFER

#include "IndexBuffer.h"

class OpenGLIndexBuffer : public IndexBuffer {
    public:

        /*!
         * @brief Creates index buffer using OpenGL
         *
         * @param indices Indices used for creating buffer
         * @param count Number of buffer indices to create  
         */
        OpenGLIndexBuffer (uint32_t* indices, uint32_t count);
        virtual ~OpenGLIndexBuffer () override;
        
        /*!
         * @brief Binds OpenGL rendering rendering context to stored buffer id
         */
        virtual void bind () const override;
        
        /*!
         * @brief Unbinds OpenGL rendering of @b any buffer
         */
        virtual void unbind () const override;
        
        /*!
         * @brief Gets index buffer count
         *
         * @return Index buffer count
         */
        virtual uint32_t getCount () const override;

    private:
        uint32_t _buffer_id;
        uint32_t _count;
};

#endif