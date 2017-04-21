#include "stdafx.h"
#include "Material.h"


Material::Material()
{
}

Material::Material(glm::vec3 v):Tetra(v)
{
}


GLuint Material::id()
{
	return GLuint(10);
}

Material::~Material()
{
}
