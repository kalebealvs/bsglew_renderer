#ifndef OPENGL_VERTEX_BUFFER_H
#define OPENGL_VERTEX_BUFFER_H

#include <GL/glew.h>
#include <memory>
#include "VertexBuffer.h"

class OpenGLVertexBuffer : public VertexBuffer {
    public:

        /*!
         * @brief Creates index buffer using OpenGL
         *
         * @param vertices Vertices used for creating buffer
         * @param count Buffer size to be created  
         */
        OpenGLVertexBuffer (float* vertices, uint32_t size);
        virtual ~OpenGLVertexBuffer ();

        /*!
         * @brief Binds OpenGL rendering context to stored buffer id
         */
        virtual void bind () const override;
        
        /*!
         * @brief Unbinds OpenGL rendering context of @b any buffer
         */
        virtual void unbind () const override;
    
    private:
        uint32_t _buffer_id;
};

#endif