#include "ShaderProgram.h"

ShaderProgram* ShaderProgram::Attach(Shader* vertex, Shader* fragment)
{
	ShaderProgram* shpClass = new ShaderProgram();
	shpClass->vertexID = vertex->GetShaderID();
	shpClass->fragmentID = fragment->GetShaderID();

	shpClass->programID = glCreateProgram();
	glAttachShader(shpClass->programID, shpClass->vertexID);
	glAttachShader(shpClass->programID, shpClass->fragmentID);
	glLinkProgram(shpClass->programID);
	glGetProgramiv(shpClass->programID, GL_LINK_STATUS, &shpClass->success);
	if (!shpClass->success) {
		glGetProgramInfoLog(shpClass->programID, 512, NULL, shpClass->infolog);
		printf("Error: Linking shader program, %s \n", shpClass->infolog);
	}

	return shpClass;
}

void ShaderProgram::Detach()
{
	if (vertexID != NULL && fragmentID != NULL)
	{
		glDetachShader(programID, vertexID);
		glDetachShader(programID, fragmentID);
	}
}

void ShaderProgram::Use()
{
	glUseProgram(programID);
}

void ShaderProgram::Delete()
{
	glDeleteProgram(programID);
}

int ShaderProgram::GetAttributeLocation(const char* location_name)
{
	return glGetAttribLocation(programID, location_name);
}

void ShaderProgram::SetBool(const char* name, bool value)
{
	float toLoad = 0;
	if (value)
	{
		toLoad = 1;
	}
	glUniform1f(glGetUniformLocation(programID, name), toLoad);
}

void ShaderProgram::SetInt(const char* name, int value)
{
	glUniform1i(glGetUniformLocation(programID, name), value);
}

void ShaderProgram::SetMat4(const char* name, const float* value)
{
	glUniformMatrix4fv(glGetUniformLocation(programID, name), 1, GL_FALSE, value);
}

void ShaderProgram::SetFloat(const char* name, float value)
{
	glUniform1f(glGetUniformBlockIndex(programID, name), value);
}