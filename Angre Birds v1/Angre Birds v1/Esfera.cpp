#include "stdafx.h"
#include "Esfera.h"

float MAS = 1;
float TIMESTAM = 1.0f / 600.0f;

Esfera::Esfera()
{
	Base::radio = 1;
	model_matrix = glm::mat4(1.0f);
	model_matrix = glm::scale(model_matrix, glm::vec3(0.25, 0.25, 0.25));
}

Esfera::Esfera(glm::vec3 v)
{	
	Base::radio = 1;
	Base::halfWidth = 1;
	Base::center = v;
	Base::timestamp = TIMESTAM;
	Base::linearVelocity = glm::vec3(0.0);
	Base::linearVelocity = glm::vec3(0.0);
	Base::mass = MAS;
	Base::elasticity = 0.75;
	Base::r_drag = 0.996;

	model_matrix = glm::mat4(1.0f);
	model_matrix = glm::translate(model_matrix, v);
	//glm::vec3 s(3.0, 3.0, 3.0);
	//model_matrix = glm::scale(model_matrix, s);
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
	return "Texturas/CERDO.bmp";
}

GLuint Esfera::id()
{
	return GLuint(2);
}
