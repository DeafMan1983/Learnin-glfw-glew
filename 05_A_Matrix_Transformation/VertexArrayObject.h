#include <gl/glew.h>

class VertexArrayObject
{
public:
	static VertexArrayObject* Gen();

	void Bind();
	void Delete();

private:
	VertexArrayObject() {};
	unsigned int vaoID;
};