#pragma once
#include "Material.h"
class Hielo :
	public Material
{
public:
	Hielo();
	Hielo(glm::vec3 v);
	virtual GLuint id();
	virtual std::string obtener_textura();
	~Hielo();
};

