#include "stdafx.h"
#include "Iniciador.h"
#include "Base.h"
#include "Tetra.h"
#include "Utilidades.h"
Iniciador::Iniciador()
{
}


Iniciador::~Iniciador()
{
}

GLuint Iniciador::buffer_vertex[5] = {0,0,0,0,0};
int Iniciador::buffer_trian[] = { 0,0,0,0,0 };
GLuint Iniciador::buffer_text[] = { 0,0,0,0,0 };
// iniciar un dibujo base
GLuint Iniciador::iniciar_base()
{
	static const GLfloat g_vertex_buffer_data[] = {
		-25.0f, 30.0f, 0.0f,
		-25.0f, -30.0f, 0.0f,
		25.0f,  -30.0f, 0.0f,
		-25.0f, 30.0f, 0.0f,
		25.0f,  -30.0f, 0.0f,
		25.0f, 30.0f, 0.0f
	};

	// Identificar el vertex buffer
	GLuint vertexbuffer;
	// Generar un buffer, poner el resultado en el vertexbuffer que acabamos de crear
	glGenBuffers(1, &vertexbuffer);
	// Los siguientes comandos le darán características especiales al 'vertexbuffer' 
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Darle nuestros vértices a  OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	
	static const GLfloat g_uv_buffer_data[] = {
		0.0f,1.0f,
		0.0f,0.0f,
		1.0f,0.0f,
		0.0f,1.0f,
		1.0f,0.0f,
		1.0f,1.0f
	};

	GLuint UV_buffer;
	glGenBuffers(1, &UV_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, UV_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
	
	
	//buffer_text[0] = Utilidades::Loadtexture("Texturas/pasto.jpg");
	//Clase a la cual asigna: BASE
	buffer_vertex[0] = vertexbuffer;
	buffer_trian[0] = 2;
	return vertexbuffer;
}


// inicia un cubo
GLuint Iniciador::iniciar_tetra()
{
	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f,-1.0f,-1.0f, // triángulo 1 : comienza
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, // triángulo 1 : termina
		1.0f, 1.0f,-1.0f, // triángulo 2 : comienza
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f, // triángulo 2 : termina
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f
	};

	// Identificar el vertex buffer
	GLuint vertexbuffer;
	// Generar un buffer, poner el resultado en el vertexbuffer que acabamos de crear
	glGenBuffers(1, &vertexbuffer);
	// Los siguientes comandos le darán características especiales al 'vertexbuffer' 
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Darle nuestros vértices a  OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	//Clase a la cual asigna: BASE
	
	buffer_vertex[1] = vertexbuffer;
	buffer_trian[1] = 12;
	return vertexbuffer;
}
