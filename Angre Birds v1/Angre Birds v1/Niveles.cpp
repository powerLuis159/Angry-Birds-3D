#include "stdafx.h"
#include "Niveles.h"


Niveles::Niveles()
{
	//Nivel 1
	escenarios[0] = Utilidades::Loadtexture("Texturas/ajedrez.bmp");

	niveles[0].push_back(new Base( glm::vec3(0.0, 0.0, 0.0)));		// Base vacia
	niveles[0].push_back(new Amarillo( glm::vec3(0.0, -25.0, 1.0)));
	niveles[0].push_back(new Amarillo(glm::vec3(0.0, -25.0, 1.0)));
	niveles[0].push_back(new Amarillo(glm::vec3(0.0, -25.0, 1.0)));
	niveles[0].push_back(new C_Especial( glm::vec3(10.0, 20.0, 15.0)));
	niveles[0].push_back(new C_Especial(glm::vec3(20.0, 20.0, 15.0)));
	niveles[0].push_back(new C_Especial(glm::vec3(-10.0, 20.0, 25.0)));
	niveles[0].push_back(new Cerdo(glm::vec3(1.5, -5.0, 10.0)));
	niveles[0].push_back(new Cerdo(glm::vec3(0.0, 0.0, 10.0)));
	niveles[0].push_back(new Cerdo(glm::vec3(-10.0, 15.0, 10.0)));
	niveles[0].push_back(new Cerdo(glm::vec3(13.0, 22.0, 15.0)));
	niveles[0].push_back(new Cerdo( glm::vec3(-18.0, 12.0, 25.0)));
	niveles[0].push_back(new Cerdo( glm::vec3(3, 5.0, 10.0)));
	niveles[0].push_back(new Madera( glm::vec3(10.0, 10.0, 10.0)));
	niveles[0].push_back(new Madera(glm::vec3(-10.0, -10.0, 10.0)));
	niveles[0].push_back(new Metal(glm::vec3(10.0, 0.0, 10.0)));
	niveles[0].push_back(new Metal(glm::vec3(13, 3.0, 10.0)));
	niveles[0].push_back(new Hielo(glm::vec3(11.0, 12.0, 10.0)));
	niveles[0].push_back(new Hielo(glm::vec3(-15.0, -8.0, 10.0)));
	niveles[0].push_back(new Hielo(glm::vec3(7.0, 2.0, 10.0)));
	//Nivel 2
	escenarios[1] = Utilidades::Loadtexture("Texturas/billar.bmp");
	//Nivel 3
	escenarios[2] = Utilidades::Loadtexture("Texturas/futbol.bmp");
}


Niveles::~Niveles()
{
	for each (auto vector in niveles)
	{
		for each (auto var in vector)
		{
			delete var;
		}
		vector.clear();
	}
}


// Devuelve los valores correspondientes a cierto nivel
std::vector<Base*> Niveles::nivel(int numero_nivel)
{

	return niveles[numero_nivel%3];
}


// devuelve la textura de un escenario en especifico
GLuint Niveles::get_escenario(int numero_nivel)
{
	return escenarios[numero_nivel];
}
