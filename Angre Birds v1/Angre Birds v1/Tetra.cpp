#include "stdafx.h"
#include "Tetra.h"


Tetra::Tetra()
{
	model_matrix = glm::mat4(1.0f);
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
	return "Objetos/esfera.obj";
}
