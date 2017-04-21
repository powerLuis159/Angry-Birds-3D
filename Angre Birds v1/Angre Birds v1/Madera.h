#pragma once
#include "Material.h"
class Madera :
	public Material
{
public:
	Madera();
	Madera(glm::vec3 v);
	virtual std::string obtener_textura();
	virtual GLuint id();
	~Madera();
};

