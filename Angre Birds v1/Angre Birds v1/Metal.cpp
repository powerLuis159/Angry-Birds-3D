#include "stdafx.h"
#include "Metal.h"


Metal::Metal()
{
}

Metal::Metal(glm::vec3 v):Material(v)
{
}

GLuint Metal::id()
{
	return GLuint(13);
}

std::string Metal::obtener_textura()
{
	return std::string("Texturas/metal.bmp");
}


Metal::~Metal()
{
}
