cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDRD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

project(imgui_example_glfw_vulkan C CXX)


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DVK_PROTOTYPES")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_PROTOTYPES")

find_package(glfw3)

# Dear ImGui
set(IMGUI_DIR ../imGUI)
set(COMPILE_LIB_DIR /home/yly/text-editor/hushu)
include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends ..)

# Libraries
find_package(Vulkan REQUIRED)
#find_library(VULKAN_LIBRARY
  #NAMES vulkan vulkan-1)
#set(LIBRARIES "glfw;${VULKAN_LIBRARY}")
set(LIBRARIES "glfw;Vulkan::Vulkan")

# Use vulkan headers from glfw:
include_directories(${GLFW_DIR}/deps)

file(GLOB sources *.cpp)

add_executable(example_glfw_vulkan ${sources} ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp ${IMGUI_DIR}/backends/imgui_impl_vulkan.cpp ${IMGUI_DIR}/imgui.cpp ${IMGUI_DIR}/imgui_draw.cpp ${IMGUI_DIR}/imgui_demo.cpp ${IMGUI_DIR}/imgui_tables.cpp ${IMGUI_DIR}/imgui_widgets.cpp)
target_link_libraries(example_glfw_vulkan  ${COMPILE_LIB_DIR}/libhushu.a ${LIBRARIES})
target_compile_definitions(example_glfw_vulkan PUBLIC -DImTextureID=ImU64)
