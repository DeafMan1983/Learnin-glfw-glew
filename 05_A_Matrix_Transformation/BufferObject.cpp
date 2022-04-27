#include "BufferObject.h"

BufferObject* BufferObject::Gen()
{
	BufferObject* boClass = new BufferObject();
	glGenBuffers(1, &boClass->boID);
	return boClass;
}

void BufferObject::Bind(GLenum buffer_type)
{
	this->buffer_type = buffer_type;
	glBindBuffer(buffer_type, boID);
}

void BufferObject::Data(int size, float vertices[], GLenum usage)
{
	glBufferData(this->buffer_type, size, vertices, usage);
}

void BufferObject::Data(int size, unsigned int indices[], GLenum usage)
{
	glBufferData(this->buffer_type, size, indices, usage);
}

void BufferObject::Pointer(int index, int size, int stride, void* pointer)
{
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, pointer);
}

void BufferObject::Enable(int index)
{
	glEnableVertexAttribArray(index);
}

void BufferObject::Disable(int index)
{
	glDisableVertexAttribArray(index);
}

void BufferObject::Delete()
{
	glDeleteBuffers(1, &boID);
}

