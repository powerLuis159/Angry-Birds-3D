#pragma once
#include "Cerdo.h"
class C_normal :
	public Cerdo
{
public:
	C_normal();
	C_normal(glm::vec3 v);
	virtual GLuint id();
	~C_normal();
};

