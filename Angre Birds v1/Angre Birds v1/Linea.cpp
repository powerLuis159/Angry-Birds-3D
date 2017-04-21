#include "stdafx.h"
#include "Linea.h"


Linea::Linea():Base()
{
	puntoA = glm::vec3(0, -30.0, 20.0);
	puntoB = glm::vec3(0, -32.0, 20.0);
	model_matrix = glm::translate(model_matrix, puntoA);
}


Linea::~Linea()
{
}

GLuint Linea::id()
{
	return GLuint(3);
}
