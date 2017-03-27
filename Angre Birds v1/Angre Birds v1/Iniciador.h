#pragma once
#include "Base.h"
class Iniciador
{
public:
	Iniciador();
	~Iniciador();
	// iniciar un dibujo base
	static GLuint iniciar_base();
	// inicia un cubo
	static GLuint iniciar_tetra();
	// Carga los valores al opengl a partir de un objeto	static GLuint buffer_indice[];
	static GLuint iniciar(Base *);
	// Buffer de vertices
	static GLuint buffer_vertex[];
	static int buffer_trian[];
	static GLuint buffer_text[];
	static GLuint buffer_indice[];
	static GLuint buffer_UV[];
};

