#include "Renderer/IndexBuffer.h"
#include "Renderer/OpenGLIndexBuffer.h"

#include <iostream>
#include <memory>

IndexBuffer::~IndexBuffer () {}

std::shared_ptr<IndexBuffer> IndexBuffer::Create (uint32_t* indices, uint32_t size) {
    enum class GraphicsAPI { None = 0, Vulkan = 1, OpenGL = 2 };// to be in separeted file
    const auto graphics_api = GraphicsAPI::OpenGL;
    switch (graphics_api) {
        case GraphicsAPI::None:
            [[fallthrough]];
        case GraphicsAPI::Vulkan:
            std::cerr << "Not supported yet";
            return nullptr;
        case GraphicsAPI::OpenGL:
            return std::make_shared<OpenGLIndexBuffer> (indices, size);
    }
}