#include <gl/glew.h>

class BufferObject
{
public:
	static BufferObject* Gen();
	void Bind(GLenum buffer_type);
	void Data(int size, float vertices[], GLenum usage);
	void Data(int size, unsigned int indices[], GLenum usage);
	void Pointer(int index, int size, int stride, void* pointer);
	void Enable(int index);
	void Disable(int index);

	void Delete();

private:
	GLenum buffer_type;
	unsigned int boID;
};

