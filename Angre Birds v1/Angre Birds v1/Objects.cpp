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
		vec.push_back(new Esfera(v));
	}
}

void Objects::move(int id, glm::vec3 v)
{
	vec[id]->center += v;
	vec[id]->upperCorner += v;
	vec[id]->lowerCorner += v;

	for(int i = 1; i<vec.size(); i++)
		if (id != i) 
		{
			if(vec[id]->collide(vec[i])){
				vec[id]->center -= v;
				vec[id]->upperCorner -= v;
				vec[id]->lowerCorner -= v;
				printf("collision ! \n");
				break;	// i = vec.size();
			}
		}
			
	vec[id]->model_matrix = glm::mat4(1.0);
	vec[id]->model_matrix = glm::translate(vec[id]->model_matrix, vec[id]->center);

	vec[id]->model_matrix = glm::rotate(vec[id]->model_matrix, vec[id]->rotation[0], glm::vec3(1.0, 0.0, 0.0));
	vec[id]->model_matrix = glm::rotate(vec[id]->model_matrix, vec[id]->rotation[1], glm::vec3(0.0, 1.0, 0.0));
	vec[id]->model_matrix = glm::rotate(vec[id]->model_matrix, vec[id]->rotation[2], glm::vec3(0.0, 0.0, 1.0));
}

void Objects::rotate(int id, float angle, glm::vec3 v)
{
	vec[id]->rotation += (v * angle);
	vec[id]->model_matrix = glm::rotate<float, glm::packed_highp>(vec[id]->model_matrix, angle, v);
}

/*void Objects::step()
{
	for (int i = 1; i < vec.size()-1; i++) 
	{
		if (vec[i]->center[2] <= 1.0) {
			//vec[i]->addForce(-GRAVITY * vec[i]->mass);
			vec[i]->linearVelocity[2] = -(vec[i]->linearVelocity[2]*0.99);

		}
		for (int j = i+1; j < vec.size(); j++) 
			if (vec[i]->circleCollision(vec[j])) 
			{
				//printf("collision!!!! %d %d\n", i,j);
				glm::vec3 normal = vec[j]->center - vec[i]->center;
				//vec[i]->linearVelocity = glm::vec3(0.0) ;
				float vel = 0.9;
				vec[i]->linearVelocity = -vec[i]->linearVelocity*vel;
				vec[j]->linearVelocity = vec[i]->linearVelocity;
			}
	}
}*/


void Objects::step() 
{
	//addGravity
	
	for (int i = 1; i < vec.size() ; i++)
	{	
		vec[i]->gravity();
	}

	for (int i = 1; i < vec.size(); i++) 
	{
		//printf("%f \n", linearVelocity[2]);
		if (vec[i]->linearVelocity != glm::vec3(0.0, 0.0, 0.0))
			vec[i]->update();
	}
	bounce();
}

int Z = 2;

float getMax(glm::vec3 v) 
{
	float max = 0;
	for (int i = 1; i < 3; i++)
		if (max < abs(v[i]))
			max = abs(v[i]);
	return max;
}

void Objects::bounce()
{
	for (int i = 1; i < vec.size(); i++)
	{
		float d = vec[i]->center[Z] - 1.0;
		if (d < 0) {
			vec[i]->center[Z] = 1.0;
			vec[i]->linearVelocity[Z] *= -(vec[i]->elasticity);		// rebota en base a la superposicion con el plano
			printf("%f\n", vec[i]->elasticity);
		}

		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[i]->circleCollision(vec[j]))
			{
				glm::vec3 normal = vec[j]->center - vec[i]->center;
				float n = getMax(normal);	normal /= n;
				float l = getMax(vec[i]->linearVelocity) / 5.;

				vec[j]->linearVelocity = normal * l;
				vec[i]->linearVelocity -= vec[j]->linearVelocity;
				
				printf("collition!!!!\n");
			}
		}
	}
}

