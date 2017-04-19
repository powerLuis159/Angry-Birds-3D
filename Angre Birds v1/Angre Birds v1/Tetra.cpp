#include "stdafx.h"
#include "Tetra.h"

float MASS = 10;
float TIMESTAMP = 1.0f / 60.0f;

Tetra::Tetra()
{
	model_matrix = glm::mat4(1.0f);
}

Tetra::Tetra(glm::vec3 v)
{
	Base::halfWidth = 1;
	Base::center = v;
	Base::timestamp = TIMESTAMP;
	Base::linearVelocity = glm::vec3(0.0);
	Base::linearVelocity = glm::vec3(0.0);
	Base::mass = MASS;

	model_matrix = glm::mat4(1.0);
	model_matrix = glm::translate(model_matrix, v);

	glm::vec3 uno(1.0, 1.0, 1.0);
	upperCorner = v + uno;
	lowerCorner = v - uno;
}

Tetra::~Tetra()
{
}

// //definir los valores de un tetraedro
void Tetra::set_vertices()
{
}

GLuint Tetra::id()
{
	return GLuint(1);
}

// Se devolvera madera por defecto
std::string Tetra::obtener_textura()
{
	return "Texturas/madera.bmp";
}


// se usara el valor de un cubo
std::string Tetra::obtener_objeto()
{
	return "Objetos/cubo.obj";
}