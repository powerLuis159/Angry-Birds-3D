#pragma once
#include "Material.h"
class Metal :
	public Material
{
public:
	Metal();
	Metal(glm::vec3 v);
	virtual GLuint id();
	virtual std::string obtener_textura();
	~Metal();
};

