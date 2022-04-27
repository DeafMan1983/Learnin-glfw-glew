#include "Transformation.h"

Transformation* Transformation::Identify()
{
	Transformation* transClass = new Transformation();
	transClass->matrixID = glm::mat4(1.0f);
	return transClass;
}

void Transformation::Translate(glm::vec3 position)
{
	matrixID = glm::translate(matrixID, position);
}

void Transformation::Rotate(float radius, glm::vec3 rotation)
{
	matrixID = glm::rotate(matrixID, radius, rotation);
}

void Transformation::Scale(glm::vec3 scalation)
{
	matrixID = glm::scale(matrixID, scalation);
}

glm::mat4 Transformation::GetMat4()
{
	return matrixID;
}