#ifndef BUFFER_H
#define BUFFER_H

class Buffer {
    public:
        virtual ~Buffer ();
        virtual void bind () const = 0;
        virtual void unbind () const = 0;
};

#endif