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
    OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
    virtual ~OpenGLIndexBuffer();

    /*!
     * @brief Binds OpenGL rendering rendering context to stored buffer id
     */
    auto bind() const -> void override;

    /*!
     * @brief Unbinds OpenGL rendering of @b any buffer
     */
    auto unbind() const -> void override;

    /*!
     * @brief Gets index buffer count
     *
     * @return Index buffer count
     */
    auto getCount() const -> uint32_t override;

private:
    uint32_t _buffer_id;
    uint32_t _count;
};

#endif
