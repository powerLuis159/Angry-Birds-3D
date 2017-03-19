#include "stdafx.h"
#include "Base.h"
#include <glm\glm.hpp>

Base::Base()
	: vertex_buffer(0)
	, UV_buffer(0)
	, texture_buffer(0)
{
}


Base::~Base()
{
}


// Funcion para cargar la textura del objeto base
GLuint Base::cargar_textura()
{
	return GLuint();
}
