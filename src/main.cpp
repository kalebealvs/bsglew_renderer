#include <array>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int, char**) {
    if (!glfwInit ())
        return -1;

    GLFWwindow* window = glfwCreateWindow (static_cast<GLint>(640),
                                           static_cast<GLint>(480),
                                           "GL_RENDER",
                                           nullptr,
                                           nullptr);
    if (!window) {
        glfwTerminate ();
        return -1;
    }

    glfwMakeContextCurrent (window);
    const int glew_status = glewInit ();
    if (GLEW_OK != glew_status) {
        std::cerr << "Oh noh! An error has happened";
        return -1;
    }

    std::cout << "OpenGL version: " << glGetString (GL_VERSION) << ".\n";


    // Create Buffer
    constexpr std::array<float, 6> coords {
        -1.f, -1.f,
         1.f, -1.f,
         0.f,  1.f
    };
    constexpr GLint data_per_vertex = 2;
    constexpr GLint vertices = coords.size () / data_per_vertex;
    GLuint buffer_id;
    glGenBuffers (1, &buffer_id);
    glBindBuffer (GL_ARRAY_BUFFER, buffer_id);
    glBufferData (GL_ARRAY_BUFFER, coords.size () * sizeof (float), coords.data (), GL_STATIC_DRAW);

    // Must enable vertex group for it to work
    glEnableVertexAttribArray (0);
    // Size in bytes of each vertex inside buffer
    const GLsizei stride = data_per_vertex * sizeof (float);
    // Pointer for the first data inside vertex
    const void* start_pointer = 0;
    // Specify vertex structure
    glVertexAttribPointer (0, data_per_vertex, GL_FLOAT, GL_FALSE, stride, start_pointer);

    while (!glfwWindowShouldClose (window)) {
        glClear (GL_COLOR_BUFFER_BIT);
        
        // Draw Call - Since we don't have an index buffer
        glDrawArrays (GL_TRIANGLES, 0, vertices);
        glfwSwapBuffers (window);
        glfwPollEvents ();
    }

    glfwTerminate ();
    return 0;
}
