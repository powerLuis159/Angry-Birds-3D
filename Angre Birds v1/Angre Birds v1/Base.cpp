#include "stdafx.h"
#include "Base.h"
#include <glm\glm.hpp>

Base::Base()
	: UV_buffer(0)
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

GLuint Base::id()
{
	return GLuint(0);
}
