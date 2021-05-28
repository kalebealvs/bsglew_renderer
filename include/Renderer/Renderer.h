#if !defined(RENDERER_H)
#define RENDERER_H

enum class RendererAPI {
    None = 0,
    Vulkan = 1,
    OpenGL = 2
};

class Renderer {
    public:
        static RendererAPI getAPI ();

    private:
        static RendererAPI _renderer_api;
};

#endif // RENDERER_H
