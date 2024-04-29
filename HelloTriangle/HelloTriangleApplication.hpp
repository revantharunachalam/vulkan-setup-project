#ifndef HELLOTRIANGLEAPP_HPP
#define HELLOTRIANGLEAPP_HPP

#include "GLFW/glfw3.h"

class HelloTriangleApplication {
    public:
        void run();

    private:
        GLFWwindow* window = NULL;
        const uint32_t WIDTH = 800;
        const uint32_t HEIGHT = 600;
        VkInstance instance;

        // Window creation
        void initWindow();

        // Vulkan functionalities
        void initVulkan();

        // Instance creation for Vulkan
        void createInstance();

        // Event loop
        void mainLoop();

        // Deallocate resources
        void cleanup();
}

#endif // HELLOTRIANGLEAPP_HPP