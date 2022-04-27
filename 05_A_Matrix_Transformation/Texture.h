#ifndef TEXTURE_H
#define TEXTURE_H

#include <gl/glew.h>

class Texture
{
public:
	static Texture* Gen();
	void Bind(GLenum texture_type);
	void Load(const char* image_path, GLenum color_pixel);
	void Activate(GLenum texture_number);
	void Parameter(GLenum key, GLenum value);
	void Delete();
	void VerticalFlip(bool flipped);
	int GetTextureID();
	int GetWidth();
	int GetHeight();
	unsigned char* GetPixels();

private:
	unsigned int textureID;
	unsigned char* data;
	int width, height, bbp;
	GLenum texture_type;
};

#endif // !TEXTURE_H