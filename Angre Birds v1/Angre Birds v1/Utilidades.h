#pragma once
class Utilidades
{
public:
	Utilidades();
	~Utilidades();
	// Carga los shaders y devuelve el programID
	static GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
	static GLuint Loadtexture(const char* file_name);
	// Carga basica de archivos *.OBJ
	static bool loadOBJ(const char* path, std::vector<glm::vec3>& out_vertices, std::vector<glm::vec2>& out_UVs, std::vector<glm::vec3>& out_normals, std::vector<unsigned int>& indices);
};

