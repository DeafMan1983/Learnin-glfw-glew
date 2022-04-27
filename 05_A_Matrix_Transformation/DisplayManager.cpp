#include "DisplayManager.h"

DisplayManager* DisplayManager::Create(const char* title, int width, int height)
{
	DisplayManager* dmClass = new DisplayManager();
	dmClass->width = width;
	dmClass->height = height;

	if (!glfwInit())
	{
		printf("Error: Initialiuing");
	}
	else
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		dmClass->window = glfwCreateWindow(width, height, title, NULL, NULL);

		if (dmClass->window == NULL)
		{
			printf("Error Creating window");
		}
		else
		{
			glfwMakeContextCurrent(dmClass->window);

			glewExperimental = GL_TRUE;

			dmClass->error = glewInit();
			if (GLEW_OK != dmClass->error)
			{
				printf("Error: GLEW doesn't support your platform.");
			}
		}
	}

	return dmClass;
}

int DisplayManager::IsRunning()
{
	int result;
	if (window != NULL)
		result = glfwWindowShouldClose(window);

	return !result;
}

void DisplayManager::Poll()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void DisplayManager::Destroy()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

GLFWwindow* DisplayManager::GetWindow()
{
	return window;
}

int DisplayManager::GetWidth()
{
	return width;
}

int DisplayManager::GetHeight()
{
	return height;
}