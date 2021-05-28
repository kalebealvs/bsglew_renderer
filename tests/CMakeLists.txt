set(VERTEX_TEST_SRC
    VertexBufferTests.cpp
)
add_executable(vertex_tests ${VERTEX_TEST_SRC})
target_link_libraries(vertex_tests
    renderer
    gmock_main
)

include(GoogleTest)
gtest_add_tests(TARGET vertex_tests)