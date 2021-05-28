#include "Renderer/Renderer.h"

RendererAPI Renderer::_renderer_api = RendererAPI::OpenGL;

RendererAPI Renderer::getAPI () {
    return _renderer_api;
}