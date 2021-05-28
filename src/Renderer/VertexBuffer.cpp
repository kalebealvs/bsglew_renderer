#include "Renderer/VertexBuffer.h"
#include "Renderer/OpenGLVertexBuffer.h"

#include <memory>
#include <iostream>

VertexBuffer::~VertexBuffer () {}

std::shared_ptr<VertexBuffer> VertexBuffer::Create (float* vertices, uint32_t size) {
    enum class GraphicsAPI { None = 0, Vulkan = 1, OpenGL = 2 };
    const auto graphics_api = GraphicsAPI::OpenGL;
    switch (graphics_api) {
        case GraphicsAPI::None:
            [[fallthrough]];
        case GraphicsAPI::Vulkan:
            std::cerr << "Not supported yet";
            return nullptr;
        case GraphicsAPI::OpenGL:
            return std::make_shared<OpenGLVertexBuffer> (vertices, size);
    }
}