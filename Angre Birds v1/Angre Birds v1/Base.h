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
	virtual GLuint id();
	// identificador de que coordenadas UV se estan usando
	GLuint UV_buffer;
	// identificador de que textura se esta usando
	GLuint texture_buffer;
	// matriz de modelado para el opengl
	glm::mat4 model_matrix=glm::mat4(1.0f);
	// Posicion del objeto en el espacio
	glm::vec3 Posicion;
	
	// devuelve el valor de la textura a ser utlizada
	virtual std::string obtener_textura();
	// devuelve el archivo OBJ que se va a utilizar
	virtual std::string obtener_objeto();
	virtual void mover();
	virtual void rotar();
};

