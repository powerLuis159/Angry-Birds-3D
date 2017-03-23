#pragma once
class Iniciador
{
public:
	Iniciador();
	~Iniciador();
	// iniciar un dibujo base
	static GLuint iniciar_base();
	// inicia un cubo
	static GLuint iniciar_tetra();
	// Array de buffer de vertices
	static GLuint buffer_vertex[5];
	// array de numero de triangulos
	static int buffer_trian[];
	// Array de texturas
	static GLuint buffer_text[];
};

