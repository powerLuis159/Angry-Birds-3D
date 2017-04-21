#include "stdafx.h"
#include "Tetra.h"



Tetra::Tetra()
{
	model_matrix = glm::mat4(1.0f);
}

Tetra::Tetra(glm::vec3 v)
{
	Base::radio = 1;
	Base::halfWidth = 1;
	Base::center = v;
	Base::timestamp = 1.0/60.0f;
	Base::linearVelocity = glm::vec3(0.0);
	Base::linearVelocity = glm::vec3(0.0);
	Base::mass = 10.0;
	Base::elasticity = 0.75;
	Base::r_drag = 0.996;

	model_matrix = glm::mat4(1.0f);
	model_matrix = glm::translate(model_matrix, v);
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
	return "Texturas/hielo.bmp";
}


// se usara el valor de un cubo
std::string Tetra::obtener_objeto()
{
	return "Objetos/cubo.obj";
}