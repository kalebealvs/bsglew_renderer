set(BUILD_GLEW FALSE)

# folder to build glew
set(GLEW_PREFIX glew)

set(NCPU 1)

add_definitions(-DGLEW_STATIC)

set(GLEW_SRC_URL https://github.com/nigels-com/glew/archive/refs/tags/glew-2.2.0.tar.gz)

message(STATUS "CMAKE_MODULE_PATH=${CMAKE_MODULE_PATH}") 

# Instructions to build
if (BUILD_GLEW)
    set(GLEW_STEP ${GLEW_PREFIX})
else (BUILD_GLEW)
    ExternalProject_Add(${GLEW_PREFIX}
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/glew
        PREFIX ${GLEW_PREFIX}
        CONFIGURE_COMMAND ""
        BUILD_COMMAND make
        BUILD_IN_SOURCE 1
        LOG_BUILD 1
        INSTALL_COMMAND ""
        STEP_TARGETS ${GLEW_PREFIX}_aut build
    )
endif(BUILD_GLEW)

# Import dir
ExternalProject_Get_Property(${GLEW_PREFIX} SOURCE_DIR)

message("Source directory of ${GLEW_PREFIX} ${SOURCE_DIR}")


# ExternalProject_Add_Step (${GLEW_PREFIX} ${GLEW_PREFIX}_cmake
#     COMMAND cmake ./cmake
#     COMMENT "Building auto first"
#     DEPENDERS build
#     WORKING_DIRECTORY ${SOURCE_DIR}/build
#     LOG 1
# )

ExternalProject_Add_Step (${GLEW_PREFIX} ${GLEW_PREFIX}_auto
    COMMAND make
    COMMENT "Building auto first"
    DEPENDERS build
    WORKING_DIRECTORY ${SOURCE_DIR}/auto
    LOG 1
)

# Set separate directories for building in Debug or Release mode
set(GLEW_DEBUG_DIR ${SOURCE_DIR}/build/${GLEW_PREFIX}_debug)
set(GLEW_RELEASE_DIR ${SOURCE_DIR}/build/${GLEW_PREFIX}_release)
message(STATUS "GLEW Debug directory ${GLEW_DEBUG_DIR}")
message(STATUS "GLEW Release directory ${GLEW_RELEASE_DIR}")

# set the include directory variable and include it
set(GLEW_INCLUDE_DIRS ${SOURCE_DIR}/include)
include_directories(${GLEW_INCLUDE_DIRS})

# link the correct GLEW directory when the project is in Debug or Release mode
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	# in Debug mode
	link_directories(${GLEW_RELEASE_DIR})
	set(GLEW_LIBS GLEW)
	set(GLEW_LIBRARY_DIRS ${GLEW_DEBUG_DIR})
else (CMAKE_BUILD_TYPE STREQUAL "Debug")
	# in Release mode
	link_directories(${GLEW_RELEASE_DIR})
	set(GLEW_LIBS GLEW)
	set(GLEW_LIBRARY_DIRS ${GLEW_RELEASE_DIR})
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

# verify that the TBB header files can be included
set(CMAKE_REQUIRED_INCLUDES_SAVE ${CMAKE_REQUIRED_INCLUDES})
set(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES} ${GLEW_INCLUDE_DIRS})
check_include_file_cxx("GL/glew.h" HAVE_GLEW)
set(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES_SAVE})
 if (NOT HAVE_GLEW)
	message(STATUS "Did not build GLEW correctly as cannot find glew.h. Will build it.")
	set(HAVE_GLEW 1)
endif (NOT HAVE_GLEW)
