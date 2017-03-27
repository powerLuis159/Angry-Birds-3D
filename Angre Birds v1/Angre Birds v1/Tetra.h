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
	// Se devolvera madera por defecto
	virtual std::string obtener_textura();
	// se usara el valor de un cubo
	std::string obtener_objeto();
};

