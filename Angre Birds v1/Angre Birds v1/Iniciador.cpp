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
GLuint Iniciador::buffer_indice[] = { 0,0,0,0,0 };
GLuint Iniciador::buffer_UV[] = { 0,0,0,0,0 };
// iniciar un dibujo base
GLuint Iniciador::iniciar_base()
{
	std::vector<unsigned int> indices;
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(3);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);

	GLuint elementbuffer;
	glGenBuffers(1, &elementbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
	buffer_indice[0] = elementbuffer;


	static const GLfloat g_vertex_buffer_data[] = {
		-25.0f, 30.0f, 0.0f,
		-25.0f, -30.0f, 0.0f,
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
		0.01f,0.98f,
		0.02f,0.02f,
		0.98f,0.02f,
		0.98f,0.98f
	};

	GLuint UV_buffer;
	glGenBuffers(1, &UV_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, UV_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
	
	buffer_UV[0] = UV_buffer;
	buffer_text[0] = Utilidades::Loadtexture("Texturas/pasto.bmp");
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

GLuint Iniciador::iniciar(Base *objeto_base)
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> UV;
	std::vector<glm::vec3> normales;//aun no se usa
	std::vector<unsigned int> indices;

	Utilidades::loadOBJ(objeto_base->obtener_objeto().data(), vertices, UV, normales, indices);
	int k = objeto_base->id();

	GLuint vertices_buffer;
	glGenBuffers(1, &vertices_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertices_buffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	GLuint UV_buffer;
	glGenBuffers(1, &UV_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, UV_buffer);
	glBufferData(GL_ARRAY_BUFFER, UV.size() * sizeof(glm::vec2), &UV[0], GL_STATIC_DRAW);

	GLuint indices_buffer;
	glGenBuffers(1, &indices_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	buffer_text[k] = Utilidades::Loadtexture(objeto_base->obtener_textura().data());
	buffer_indice[k] = indices_buffer;
	buffer_UV[k] = UV_buffer;
	buffer_vertex[k] = vertices_buffer;
	buffer_trian[k] = indices.size() / 3;


	return vertices_buffer;
}


