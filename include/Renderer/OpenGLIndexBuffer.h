#ifndef OPENGL_INDEX_BUFFER
#define OPENGL_INDEX_BUFFER

#include "IndexBuffer.h"

class OpenGLIndexBuffer : public IndexBuffer {
    public:
        OpenGLIndexBuffer (uint32_t* indices, uint32_t quantity);
        virtual ~OpenGLIndexBuffer () override;
        virtual void bind () const override;
        virtual void unbind () const override;
        virtual uint32_t getCount () const override;

    private:
        uint32_t _buffer_id;
        uint32_t _count;
};

#endif