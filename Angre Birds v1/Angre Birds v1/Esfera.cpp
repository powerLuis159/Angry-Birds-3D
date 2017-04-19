#include "stdafx.h"
#include "Esfera.h"


Esfera::Esfera()
	: Radio(0)
{
	model_matrix = glm::mat4(1.0f);
	model_matrix = glm::translate(model_matrix, glm::vec3(0.0, 0.0, 8.0));
	//model_matrix = glm::scale(model_matrix, glm::vec3(5.0, 5.0, 5.0));
}


Esfera::~Esfera()
{
}

std::string Esfera::obtener_objeto()
{
	return "Objetos/esferaER.obj";
}

std::string Esfera::obtener_textura()
{
	return "Texturas/REDER.bmp";
}

GLuint Esfera::id()
{
	return GLuint(2);
}
