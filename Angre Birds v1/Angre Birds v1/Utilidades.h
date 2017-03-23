#pragma once
class Utilidades
{
public:
	Utilidades();
	~Utilidades();
	// Carga los shaders y devuelve el programID
	static GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
	static GLuint Loadtexture(const char* file_name);
};

