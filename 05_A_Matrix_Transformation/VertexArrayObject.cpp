#include "VertexArrayObject.h"

VertexArrayObject* VertexArrayObject::Gen()
{
	VertexArrayObject* vaoClass = new VertexArrayObject();
	glGenVertexArrays(1, &vaoClass->vaoID);
	return vaoClass;
}

void VertexArrayObject::Bind()
{
	glBindVertexArray(vaoID);
}

void VertexArrayObject::Delete()
{
	glDeleteVertexArrays(1, &vaoID);
}
