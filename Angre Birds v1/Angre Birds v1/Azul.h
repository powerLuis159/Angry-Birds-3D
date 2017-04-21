#pragma once
#include "Ave.h"
class Azul :
	public Ave
{
public:
	Azul();
	Azul(glm::vec3 v);
	virtual GLuint id();
	virtual std::string obtener_textura();
	~Azul();
};

