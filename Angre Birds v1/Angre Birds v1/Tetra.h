#pragma once
#include "Base.h"
class Tetra :
	public Base
{
public:
	
	Tetra();
	virtual ~Tetra();
	// //definir los valores de un tetraedro
	void set_vertices();
	// identificador
	virtual GLuint id();
};

