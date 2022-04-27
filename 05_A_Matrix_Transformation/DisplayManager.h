#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class DisplayManager
{
public:
	static DisplayManager* Create(const char* title, int width, int height);
	int IsRunning();
	void Poll();
	void Destroy();

	int GetWidth();
	int GetHeight();
	GLFWwindow* GetWindow();

private:
	DisplayManager(){}
	GLFWwindow* window;
	int width;
	int height;

	GLenum error;
};

#endif // !DISPLAYMANAGER_H