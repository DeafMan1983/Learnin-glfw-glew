#ifndef RENDERER_H
#define RENDERER_H

#include <gl/glew.h>

class Renderer
{
public:
	static Renderer* Prepare(GLenum clear_mask, float red, float green, float blue);
	void Draw(GLenum primitive_type, unsigned int first, int count);
	void Draw(GLenum primitive_type, int count, GLenum draw_unit, const void* indices);
private:
	Renderer(){}
};

#endif // RENDERER_H