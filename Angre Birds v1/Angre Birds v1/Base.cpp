#include "stdafx.h"
#include "Base.h"
#include <glm\glm.hpp>

glm::vec3 GRAVIT(0.0, 0.0, -9.8);

Base::Base()
	: UV_buffer(0)
	, texture_buffer(0)
	, halfWidth(1)
{
}

Base::Base(glm::vec3 v)
	:halfWidth(1), center(v), 
	//mass(10.0), timestamp(0.01),
	linearVelocity(0.0), angularVelocity(0.0)
{
	model_matrix = glm::mat4(1.0);
	model_matrix = glm::translate(model_matrix, v);

	glm::vec3 uno(1.0, 1.0, 1.0);
	upperCorner = v + uno;
	lowerCorner = v - uno;
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
	return "Texturas/madera.bmp";
}


// devuelve el archivo OBJ que se va a utilizar
std::string Base::obtener_objeto()
{
	return "";
}

void Base::mover(glm::vec3 v)	
{
	center += v;
	model_matrix = glm::mat4(1.0);
	model_matrix = glm::translate(model_matrix, center);

}

void Base::rotar(float angle, glm::vec3) {}

bool Base::collide(Base *b) 
{ 
	//printf("0 ----- %f %f %f\n", this->center[0], b->center[0], abs(this->center[0] - b->center[0]));
	if (abs(center[0] - b->center[0]) > halfWidth + halfWidth)	return false;
	//printf("1 ----- %f %f %f\n", this->center[1], b->center[1], abs(this->center[1] - b->center[1]));
	if (abs(center[1] - b->center[1]) > halfWidth + halfWidth)	return false;
	//printf("2 ----- %f %f %f\n", this->center[2], b->center[2], abs(this->center[2] - b->center[2]));
	if (abs(center[2] - b->center[2]) > halfWidth + halfWidth)	return false;

	return true;
}

void Base::gravity() 
{
	
	glm::vec3 acc(0.0, 0.0, -9.8);
	linearVelocity += acc * timestamp;
	//printf("%f \n", linearVelocity[2]);
}

void Base::push(glm::vec3 v)
{
	linearVelocity += v;
}

float Base::getAngle(glm::vec3 v)
{
	float a = 0.0;
	for (int i = 0; i < 3; i++)
	{
		a += linearVelocity[i] * v[i];
	}

	float x = sqrt((linearVelocity[0] * linearVelocity[0]) + (linearVelocity[1] * linearVelocity[1]) + (linearVelocity[2] * linearVelocity[2]));
	float y = sqrt((v[0] * v[0]) + (v[1] * v[1]) + (v[2] * v[2]));

	return a / (x*y);
}

void Base::addForce(glm::vec3 f)
{
	force = f;
	acceleration = f / mass;
	linearVelocity += acceleration * timestamp;
	printf("%f %f \n", acceleration[1], timestamp);
}

void Base::applyImpulse()
{
	if (linearVelocity != glm::vec3(0.0)) {	
		acceleration += GRAVIT*timestamp;
		linearVelocity += acceleration * timestamp;
		mover(linearVelocity * timestamp );
	}
}

float euclidea(glm::vec3 a, glm::vec3 b) {
	float s = 0.0;
	s += pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2) + pow(a[2] - b[2], 2);
	s = sqrt(s);

	return s;
}

bool Base::circleCollision(Base * b)
{
	//printf("%f %f", euclidea(center, b->center), 2 * radio);
	if ( euclidea(center, b->center) < (2 * radio))
		return true;
	return false;
}

void Base::update()
{
	mover(linearVelocity);
	linearVelocity *= r_drag;

	for (int i = 0; i < 3; i++)
	{
		//printf("\t%f\n", linearVelocity[i]);
		if (abs(linearVelocity[i]) < 0.01) {
			linearVelocity[i] = 0.0;
		}
	}
}		


