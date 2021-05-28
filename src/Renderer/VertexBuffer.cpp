#include "Renderer/VertexBuffer.h"
#include "Renderer/OpenGLVertexBuffer.h"
#include "Renderer/Renderer.h"

#include <memory>
#include <iostream>

VertexBuffer::~VertexBuffer () {}

std::shared_ptr<VertexBuffer> VertexBuffer::Create (float* vertices, uint32_t size) {
    switch (Renderer::getAPI ()) {
        case RendererAPI::None:
            [[fallthrough]];
        case RendererAPI::Vulkan:
            std::cerr << "Not supported yet";
            return nullptr;
        case RendererAPI::OpenGL:
            return std::make_shared<OpenGLVertexBuffer> (vertices, size);
    }
}