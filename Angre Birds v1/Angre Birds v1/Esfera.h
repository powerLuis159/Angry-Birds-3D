#pragma once
#include "Base.h"
class Esfera :
	public Base
{
public:
	Esfera();
	Esfera(glm::vec3);
	virtual ~Esfera();
	virtual std::string obtener_objeto();
	virtual std::string obtener_textura();
	virtual GLuint id();
private:
	// Radio de la esfera
	
};

