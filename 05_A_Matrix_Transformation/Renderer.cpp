#include "Renderer.h"

Renderer* Renderer::Prepare(GLenum clear_mask, float red, float green, float blue)
{
	glClearColor(red, green, blue, 1.0f);
	glClear(clear_mask);

	return new Renderer();
}

void Renderer::Draw(GLenum primitive_type, unsigned int first, int count)
{
	glDrawArrays(primitive_type, first, count);
}

void Renderer::Draw(GLenum primitive_type, int count, GLenum draw_unit, const void* indices)
{
	glDrawElements(primitive_type, count, draw_unit, indices);
}