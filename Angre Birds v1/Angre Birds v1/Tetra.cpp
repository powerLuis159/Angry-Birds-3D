#include "stdafx.h"
#include "Tetra.h"


Tetra::Tetra()
{
	model_matrix = glm::mat4(1.0f);
}

Tetra::Tetra(glm::vec3 v)
{
	model_matrix = glm::mat4(1.0);
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
	return "Texturas/madera.bmp";
}


// se usara el valor de un cubo
std::string Tetra::obtener_objeto()
{
	return "Objetos/cubo.obj";
}


// mueve
void Tetra::mover()
{
	model_matrix = glm::translate(model_matrix, glm::vec3(0.0, 0.0, 0.1));
}

void Tetra::rotar()
{
	glm::vec3 a(1.0, 0.0, 0.0);
	model_matrix = glm::rotate<float,glm::packed_highp>(model_matrix, 0.055,a);
}
