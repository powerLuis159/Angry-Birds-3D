#pragma once
#include "Esfera.h"
class Cerdo :
	public Esfera
{
public:
	Cerdo();
	Cerdo(glm::vec3 v);
	virtual GLuint id();
	virtual ~Cerdo();
};

