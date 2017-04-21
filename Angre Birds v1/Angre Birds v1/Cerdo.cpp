#include "stdafx.h"
#include "Cerdo.h"


Cerdo::Cerdo()
{
}

Cerdo::Cerdo(glm::vec3 v):Esfera(v)
{
}

GLuint Cerdo::id()
{
	return GLuint(7);
}


Cerdo::~Cerdo()
{
}
