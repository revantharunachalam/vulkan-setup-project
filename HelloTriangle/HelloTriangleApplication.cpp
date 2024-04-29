#include <vulkan/vulkan.h>

#include "HelloTriangleApplication.hpp"

void HelloTriangleApplication::run(){
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void HelloTriangleApplication::initWindow(){
    // By default the GLFW will create window with OpenGL context. Disabling that as we are using Vulkan
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // Turning off resizeable window
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan Window", nullptr, nullptr);
}

void HelloTriangleApplication::mainLoop(){
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void HelloTriangleApplication::cleanup(){
    glfwDestroyWindow(window);
    glfwTerminate();
}

void HelloTriangleApplication::initVulkan(){
    createInstance();
}

void HelloTriangleApplication::createInstance(){
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Traiangle";
    appInfo.pApplicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    creatInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionsCount;
    createInfo.ppEnbledExtensions = glfwExtensions; // Next chapter

    createInfo.eanbledLayerCount = 0;

    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

    // Error check
    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("\n --------- Failed to create Instance ! -------------\n");
    }
}

void HelloTriangleApplication::cleanup(){
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
}