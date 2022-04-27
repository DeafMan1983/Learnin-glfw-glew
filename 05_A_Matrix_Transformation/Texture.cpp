#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

Texture* Texture::Gen()
{
	Texture* texClass = new Texture();
	glGenTextures(1, &texClass->textureID);
	return texClass;
}

void Texture::Bind(GLenum texture_type)
{	
	this->texture_type = texture_type;
	glBindTexture(texture_type, textureID);
}

void Texture::Load(const char* image_path, GLenum color_pixel)
{
	data = stbi_load(image_path, &width, &height, &bbp, 0);
	glTexImage2D(this->texture_type, 0, color_pixel, width, height, 0, color_pixel, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(this->texture_type);
	stbi_image_free(data);
}

void Texture::Activate(GLenum texture_number)
{
	glActiveTexture(texture_number);
}

void Texture::Parameter(GLenum key, GLenum value)
{
	glTexParameteri(this->texture_type, key, value);
}

void Texture::Delete()
{
	glDeleteTextures(1, &textureID);
}

void Texture::VerticalFlip(bool flipped)
{
	stbi_set_flip_vertically_on_load(flipped);
}

int Texture::GetTextureID()
{
	return textureID;
}

int Texture::GetWidth()
{
	return width;
}

int Texture::GetHeight()
{
	return height;
}

unsigned char* Texture::GetPixels()
{
	return data;
}