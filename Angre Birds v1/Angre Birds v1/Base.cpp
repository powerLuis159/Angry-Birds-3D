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


// //devuelve el valor de la textura a ser utlizada
std::string Base::obtener_textura()
{
	return "Texturas/pasto.bmp";
}


// devuelve el archivo OBJ que se va a utilizar
std::string Base::obtener_objeto()
{
	return "";
}

void Base::mover()
{
}

void Base::rotar()
{
}
