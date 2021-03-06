#include "Renderer/VertexBuffer.h"

#include <iostream>
#include <memory>

#include "Renderer/OpenGLVertexBuffer.h"
#include "Renderer/Renderer.h"

VertexBuffer::~VertexBuffer() = default;

auto VertexBuffer::Create(float* vertices, uint32_t size) -> std::shared_ptr<VertexBuffer> {
    switch (Renderer::getAPI()) {
        case RendererAPI::None:
            [[fallthrough]];
        case RendererAPI::Vulkan:
            std::cerr << "Not supported yet";
            return nullptr;
        case RendererAPI::OpenGL:
            return std::make_shared<OpenGLVertexBuffer>(vertices, size);
    }
}
