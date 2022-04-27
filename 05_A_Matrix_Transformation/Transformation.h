#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transformation
{
public:
	static Transformation* Identify();
	void Translate(glm::vec3 position);
	void Rotate(float radius, glm::vec3 rotation);
	void Scale(glm::vec3 scalation);

	glm::mat4 GetMat4();

private:
	glm::mat4 matrixID;
};

#endif // !TRANSFORMATION_H