#pragma once
#include "Ave.h"
class Amarillo :
	public Ave
{
public:
	Amarillo();
	Amarillo(glm::vec3 v);
	virtual GLuint id();
	virtual std::string obtener_textura();
	~Amarillo();
};

