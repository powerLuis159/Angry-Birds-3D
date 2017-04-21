#include "stdafx.h"
#include "Objects.h"

glm::vec3 GRAVITY(0.0, 0.0, -0.98);

Objects::Objects()
{
}

Objects::~Objects()
{
}

int halfWidth = 1;
bool collide(Base *a, Base * b)
{
	//printf(" ----- %f %f %f\n", a->center[1], b->center[1], abs(a->center[1] - b->center[1]));
	if (abs(a->center[0] - b->center[0]) > halfWidth + halfWidth)	return false;
	if (abs(a->center[1] - b->center[1]) > halfWidth + halfWidth)	return false;
	if (abs(a->center[2] - b->center[2]) > halfWidth + halfWidth)	return false;

	return true;
}


void Objects::add(int id, glm::vec3 v)
{
	if (id == BASE)
		vec.push_back(new Base);
	else
	if (id == SQUARE) {
		vec.push_back(new Tetra(v));
	}
	else
	if (id == SPHERE) {
		vec.push_back(new Rojo(v));
	}
}

void Objects::rotate(int id, float angle, glm::vec3 v)
{
	vec[id]->rotation += (v * angle);
	vec[id]->model_matrix = glm::rotate(vec[id]->model_matrix, angle, v);
}

void Objects::step() 
{
	//addGravity
	
	for (int i = 3; i < vec.size() ; i++)
	{	
		vec[i]->gravity();
	}

	for (int i = 3; i < vec.size(); i++) 
	{
		if (vec[i]->linearVelocity != glm::vec3(0.0, 0.0, 0.0))
			vec[i]->update();
	}
	bounce();
}

int Z = 2;

float norm(glm::vec3 v) 
{
	float n = 0;
	for (int i = 0; i < 3; i++)
		n += v[i] * v[i];
			
	return sqrt(n);
}

void Objects::bounce()
{
	for (int i = 3; i < vec.size(); i++)
	{
		float d = vec[i]->center[Z] - 1.0;
		float x = abs(vec[i]->center[0]);
		float y = abs(vec[i]->center[1]);
		if (d < 0 &&  x < 25 && y < 30) {
			vec[i]->center[Z] = 1.0;
			vec[i]->linearVelocity[Z] *= -(vec[i]->elasticity);		// rebota en base a la superposicion con el plano
		}

		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[i]->circleCollision(vec[j]))
			{
				glm::vec3 normal = vec[j]->center - vec[i]->center;
				float n = norm(normal);
				float l = norm(vec[i]->linearVelocity);

				vec[j]->linearVelocity = normal * (l/n) * vec[j]->elasticity;
				vec[i]->linearVelocity -= vec[j]->linearVelocity;
				
				printf("collition!!!!\n");
			}
		}
	}
}

