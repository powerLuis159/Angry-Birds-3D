#pragma once
#include "Ave.h"
class Rojo :
	public Ave
{
public:
	Rojo();
	Rojo(glm::vec3);
	virtual GLuint id();
	~Rojo();
};

