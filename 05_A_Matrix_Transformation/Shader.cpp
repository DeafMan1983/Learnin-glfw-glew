#include "Shader.h"

Shader* Shader::Create(GLenum shader_type, const char* shader_source)
{
	Shader* shaClass = new Shader();
	shaClass->shaderID = glCreateShader(shader_type);
	glShaderSource(shaClass->shaderID, 1, &shader_source, NULL);
	glCompileShader(shaClass->shaderID);
	glGetShaderiv(shaClass->shaderID, GL_COMPILE_STATUS, &shaClass->success);
	if (!shaClass->success)
	{
		glGetShaderInfoLog(shaClass->shaderID, 512, NULL, shaClass->infolog);
		printf("Error: Compiling shader %s, \n", shaClass->infolog);
	}

	return shaClass;
}

void Shader::Delete()
{
	glDeleteShader(shaderID);
}

unsigned int Shader::GetShaderID()
{
	return shaderID;
}