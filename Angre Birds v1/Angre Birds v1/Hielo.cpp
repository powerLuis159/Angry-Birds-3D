#include "stdafx.h"
#include "Hielo.h"


Hielo::Hielo()
{
}

Hielo::Hielo(glm::vec3 v):Material(v)
{
}

GLuint Hielo::id()
{
	return GLuint(12);
}

std::string Hielo::obtener_textura()
{
	return std::string("Texturas/hielo.bmp");
}


Hielo::~Hielo()
{
}
