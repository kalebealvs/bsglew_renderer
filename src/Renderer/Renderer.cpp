#include "Renderer/Renderer.h"

RendererAPI Renderer::_renderer_api = RendererAPI::OpenGL;

auto Renderer::getAPI() -> RendererAPI { return _renderer_api; }
