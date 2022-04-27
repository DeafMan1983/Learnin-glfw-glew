#ifndef SHADER_H
#define SHADER_H

#include <gl/glew.h>
#include <iostream>

class Shader
{
public:
	static Shader* Create(GLenum shader_type, const char* shader_source);
	void Delete();
	unsigned int GetShaderID();

private:
	Shader(){}
	unsigned int shaderID;
	int success;
	char infolog[512];
};

#endif // !SHADER_H