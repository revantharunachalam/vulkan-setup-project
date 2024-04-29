#define GLFW_INCLUDE_VULKAN

#include "vulkan/vulkan.h"
#include "GLFW/glfw3.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include "glm/glm.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "HelloTriangle/HelloTriangleApplication.hpp"

#include <iostream>
#include <stdexcept>
#include <cstdlib>

int main(void) {
   HelloTriangleApplication *hellotriangle = new HelloTriangleApplication();
   hellotriangle->run();

   return 0;
}