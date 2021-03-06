cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

# Set CMAKE_BUILD_TYPE to Release by default.
# Must be done before calling project()
if(CMAKE_BUILD_TYPE MATCHES "^CMAKE_BUILD_TYPE$")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "" Release Debug RelWithDebInfo MinSizeRel)
endif()

project(moGL)
option(MOGL_BUILD_TESTS "build-tests" OFF)
option(MOGL_BUILD_EXAMPLES "build-examples" OFF)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE files "mogl/*.hpp" "mogl/*.inl")
file(WRITE ${PROJECT_BINARY_DIR}/__dummy.cpp)
add_library(moGL STATIC ${PROJECT_BINARY_DIR}/__dummy.cpp ${files})
set_target_properties(moGL PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(moGL INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

set(INSTALL_CMAKE_DIR lib${LIB_SUFFIX}/cmake/mogl CACHE PATH "Installation directory for cmake config files")

install(DIRECTORY mogl DESTINATION include FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY mogl DESTINATION include FILES_MATCHING PATTERN "*.inl")

configure_file(cmake/moGLConfig.cmake.in ${PROJECT_BINARY_DIR}/moGLConfig.cmake @ONLY)
install(FILES ${PROJECT_BINARY_DIR}/moGLConfig.cmake DESTINATION ${INSTALL_CMAKE_DIR})

if(MOGL_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

if(MOGL_BUILD_EXAMPLES)
    add_subdirectory(example)
endif()
