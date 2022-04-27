#include "ProcessInputManager.h"

void ProcessInputManager::FrameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

ProcessInputManager::ProcessInputManager(GLFWwindow* window)
{
	this->window = window;
}

void ProcessInputManager::FrameBufferSize(GLFWframebuffersizefun funcPtr)
{
	if (window != NULL)
		glfwSetFramebufferSizeCallback(window,  funcPtr);
}

void ProcessInputManager::Close()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(this->window, true);
}

void ProcessInputManager::SwitchFillAndLine()
{
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}