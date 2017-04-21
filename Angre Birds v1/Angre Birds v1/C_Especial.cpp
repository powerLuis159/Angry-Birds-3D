#include "stdafx.h"
#include "C_Especial.h"


C_Especial::C_Especial()
{
}

C_Especial::C_Especial(glm::vec3 v):Cerdo(v)
{
}

GLuint C_Especial::id()
{
	return GLuint(9);
}

std::string C_Especial::obtener_textura()
{
	return std::string("Texturas/CERDOB.bmp");
}


C_Especial::~C_Especial()
{
}
