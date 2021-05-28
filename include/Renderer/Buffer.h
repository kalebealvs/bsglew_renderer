#ifndef BUFFER_H
#define BUFFER_H

class Buffer {
    public:
        virtual ~Buffer ();

        /*!
         * @brief Binds context to buffer
         */
        virtual void bind () const = 0;

        /*!
         * @brief Unbinds context to buffer
         */
        virtual void unbind () const = 0;
};

#endif