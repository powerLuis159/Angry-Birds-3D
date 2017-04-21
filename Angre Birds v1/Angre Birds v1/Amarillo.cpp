#include "stdafx.h"
#include "Amarillo.h"


Amarillo::Amarillo()
{
}

Amarillo::Amarillo(glm::vec3 v):Ave(v)
{
}

GLuint Amarillo::id()
{
	return GLuint(6);
}

std::string Amarillo::obtener_textura()
{
	return std::string("Texturas/amarillo.bmp");
}


Amarillo::~Amarillo()
{
}
