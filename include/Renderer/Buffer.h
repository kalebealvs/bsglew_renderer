#ifndef BUFFER_H
#define BUFFER_H

class Buffer {
public:
    virtual ~Buffer();

    /*!
     * @brief Binds context to buffer
     */
    virtual auto bind() const -> void = 0;

    /*!
     * @brief Unbinds context to buffer
     */
    virtual auto unbind() const -> void = 0;
};

#endif
