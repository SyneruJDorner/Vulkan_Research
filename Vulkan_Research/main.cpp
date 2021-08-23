#define GLFW_INCLUDE_VULKAN //exists in GLFW
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); //Set it up case we ddont was OpenGL or embeded systems, instead we hinting at using a different external API, vulkan
	GLFWwindow* window = glfwCreateWindow(800, 600, "Test Window", nullptr, nullptr);

	uint32_t exttensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &exttensionCount, nullptr);

	printf("Extension count: %i\n", exttensionCount);

	glm::mat4 testMatrix(1.0f);
	glm::vec4 testVector(1.0f);

	auto testResult = testMatrix * testVector;

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}