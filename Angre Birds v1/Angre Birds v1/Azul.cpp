#include "stdafx.h"
#include "Azul.h"


Azul::Azul()
{
}

Azul::Azul(glm::vec3 v):Ave(v)
{
}

GLuint Azul::id()
{
	return GLuint(5);
}

std::string Azul::obtener_textura()
{
	return std::string("Texturas/Azul.bmp");
}


Azul::~Azul()
{
}
