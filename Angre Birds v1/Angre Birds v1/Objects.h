#pragma once

#include "Tetra.h"
#include "Esfera.h"

enum objectsId { BASE, SPHERE, SQUARE };

class Objects
{
public:
	std::vector<Base*> vec;
	std::vector<Base> vec2;

public:
	Objects();
	~Objects();

	void add(int , glm::vec3);
	void rotate(int, float, glm::vec3);

	void step();
	void bounce();
};

