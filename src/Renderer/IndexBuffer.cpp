#include "Renderer/IndexBuffer.h"
#include "Renderer/OpenGLIndexBuffer.h"
#include "Renderer/Renderer.h"

#include <iostream>
#include <memory>

IndexBuffer::~IndexBuffer () {}

std::shared_ptr<IndexBuffer> IndexBuffer::Create (uint32_t* indices, uint32_t size) {
    switch (Renderer::getAPI ()) {
        case RendererAPI::None:
            [[fallthrough]];
        case RendererAPI::Vulkan:
            std::cerr << "Not supported yet";
            return nullptr;
        case RendererAPI::OpenGL:
            return std::make_shared<OpenGLIndexBuffer> (indices, size);
    }
}