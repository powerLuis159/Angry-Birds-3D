#pragma once
#include "Tetra.h"
class Material :
	public Tetra
{
public:
	Material();
	Material(glm::vec3);
	virtual GLuint id();
	virtual ~Material();
};

