#include "stdafx.h"
#include "Ave.h"


Ave::Ave()
{
}

Ave::Ave(glm::vec3 v):Esfera(v)
{
}


Ave::~Ave()
{
}

std::string Ave::obtener_textura()
{
	return std::string("Texturas/RED.bmp");
}

GLuint Ave::id()
{
	return GLuint(3);
}

