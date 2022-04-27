#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "Shader.h";

class ShaderProgram
{
public:
	static ShaderProgram* Attach(Shader* vertex, Shader* fragment);
	void Detach();
	void Use();
	void Delete();

	int GetAttributeLocation(const char* location_name);
	void SetBool(const char* name, bool value);
	void SetInt(const char* name, int value);
	void SetFloat(const char* name, float value);
	void SetMat4(const char* name, const float* value);

private:
	unsigned int programID;
	unsigned int vertexID;
	unsigned int fragmentID;
	int success;
	char infolog[1024];
};

#endif // !SHADERPROGRAM_H