cmake_minimum_required(VERSION 2.8.12)
project(demo-ci-conan)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SOURCES src/libB.cpp)
file(GLOB HEADERS include/libB/*)

add_library(libB ${SOURCES} ${HEADERS})
set_target_properties(libB PROPERTIES CXX_STANDARD 17)
target_link_libraries(libB PRIVATE CONAN_PKG::libA CONAN_PKG::libF)

target_include_directories(
    libB PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS libB
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(FILES ${HEADERS}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/libB
        PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ)
