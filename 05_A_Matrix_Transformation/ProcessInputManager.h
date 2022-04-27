#ifndef PROCESSINPUTMANAGER_H
#define PROCESSINPUTMANAGER_H

#include <GLFW/glfw3.h>

class ProcessInputManager
{
public:
	ProcessInputManager(GLFWwindow* window);
	void FrameBufferSize(GLFWframebuffersizefun funcPtr);
	void Close();
	void SwitchFillAndLine();

	static void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);

private:
	GLFWwindow* window;
};

#endif // !PROCESSINPUTMANAGER_H