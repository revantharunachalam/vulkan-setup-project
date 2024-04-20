cmake_minimum_required(VERSION 3.29.2)

project(VulkanSetupProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find Vulkan package
find_package(Vulkan REQUIRED)

# Add executable
add_executable(VulkanApp main.cpp)

# Setting path of GLFW3 lib
set(GLFW_LIBRARIES ${CMAKE_SOURCE_DIR}/Dependencies/GLFW/lib-vc2022/glfw3.lib)

# Specify linker options
target_link_options(VulkanApp PRIVATE "/NODEFAULTLIB:MSVCRT")

# Link libraries
target_link_libraries(VulkanApp ${Vulkan_LIBRARIES} ${GLFW_LIBRARIES})

# Include Vulkan headers
target_include_directories(VulkanApp PRIVATE 
    ${Vulkan_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLFW/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLM
)
