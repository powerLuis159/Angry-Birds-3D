#pragma once
class Base
{
public:
	
	Base();
	virtual ~Base();
	// //vida del objeto, si esta llega a 0. No debe ser dibujado mas.
	int hit_points;
	//nombre de la tetura---posiblemente se remueva
	std::string textura;
	// Funcion para cargar la textura del objeto base
	GLuint cargar_textura();
	// identificador de que vertices esta usando.
	GLuint vertex_buffer;
	// identificador de que coordenadas UV se estan usando
	GLuint UV_buffer;
	// identificador de que textura se esta usando
	GLuint texture_buffer;
	// matriz de modelado para el opengl
	glm::mat4 model_matrix;
	// Posicion del objeto en el espacio
	glm::vec3 Posicion;
};

