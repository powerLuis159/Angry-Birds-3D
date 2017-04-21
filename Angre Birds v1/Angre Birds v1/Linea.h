#pragma once
#include "Base.h"
class Linea :
	public Base
{
public:
	glm::vec3 puntoA, puntoB;

	Linea();
	virtual ~Linea();

	GLuint id();
};

