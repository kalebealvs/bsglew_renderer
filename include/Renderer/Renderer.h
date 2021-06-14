#if !defined(RENDERER_H)
#define RENDERER_H

enum class RendererAPI { None = 0, Vulkan = 1, OpenGL = 2 };

class Renderer {
public:
    /*!
     * @brief Returns current rendering API
     *
     * @return Current rendring API
     */
    static auto getAPI() -> RendererAPI;

private:
    static RendererAPI _renderer_api;
};

#endif  // RENDERER_H
