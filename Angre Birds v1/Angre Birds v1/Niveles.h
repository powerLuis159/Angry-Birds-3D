#pragma once
#include "Base.h"
#include "Rojo.h"
#include "Amarillo.h"
#include "Azul.h"
#include "Cerdo.h"
#include "C_Especial.h"
#include "Metal.h"
#include "Hielo.h"
#include "Madera.h"
#include "Utilidades.h"
class Niveles
{
private:
	GLuint escenarios[3];
	std::vector<Base*> niveles[3];
public:
	Niveles();
	~Niveles();
	// Devuelve los valores correspondientes a cierto nivel
	std::vector<Base*> nivel(int numero_nivel);
	// devuelve la textura de un escenario en especifico
	GLuint get_escenario(int numero_nivel);
};

