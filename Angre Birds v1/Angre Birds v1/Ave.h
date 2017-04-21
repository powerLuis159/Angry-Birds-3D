#pragma once
#include "Esfera.h"
class Ave :
	public Esfera
{
public:
	Ave();
	Ave(glm::vec3);
	virtual ~Ave();
	virtual std::string obtener_textura();
	virtual GLuint id();
};

