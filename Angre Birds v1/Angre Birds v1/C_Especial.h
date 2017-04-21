#pragma once
#include "Cerdo.h"
class C_Especial :
	public Cerdo
{
public:
	C_Especial();
	C_Especial(glm::vec3 v);
	virtual GLuint id();
	virtual std::string obtener_textura();
	~C_Especial();
};

