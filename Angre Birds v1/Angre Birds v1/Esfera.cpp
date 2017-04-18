#include "stdafx.h"
#include "Esfera.h"


Esfera::Esfera()
	: Radio(0)
{
	model_matrix = glm::mat4(1.0f);
	model_matrix = glm::scale(model_matrix, glm::vec3(2.0, 2.0, 2.0));
}


Esfera::~Esfera()
{
}

std::string Esfera::obtener_objeto()
{
	return "Objetos/esfera.obj";
}

std::string Esfera::obtener_textura()
{
	return "Texturas/madera - copia.bmp";
}

GLuint Esfera::id()
{
	return GLuint(2);
}
