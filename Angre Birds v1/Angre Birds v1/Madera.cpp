#include "stdafx.h"
#include "Madera.h"


Madera::Madera()
{
}

Madera::Madera(glm::vec3 v):Material(v)
{
}

std::string Madera::obtener_textura()
{
	return std::string("Texturas/madera.bmp");
}

GLuint Madera::id()
{
	return GLuint(11);
}


Madera::~Madera()
{
}
