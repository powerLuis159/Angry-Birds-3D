#include "stdafx.h"
#include "Utilidades.h"
#include <vector>
#include <fstream>

Utilidades::Utilidades()
{
}


Utilidades::~Utilidades()
{
}


// Carga los shaders y devuelve el programID
GLuint Utilidades::LoadShaders(const char* vertex_file_path, const char* fragment_file_path)
{
	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if (VertexShaderStream.is_open()) {
		std::string Line = "";
		while (getline(VertexShaderStream, Line))
			VertexShaderCode += "\n" + Line;
		VertexShaderStream.close();
	}
	else {
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
		getchar();
		return 0;
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if (FragmentShaderStream.is_open()) {
		std::string Line = "";
		while (getline(FragmentShaderStream, Line))
			FragmentShaderCode += "\n" + Line;
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;


	// Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}



	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}



	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}


	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}

GLuint Utilidades::Loadtexture(const char * file_name)
{
	// Lectura de información del encabezado del archivo
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
							  // Información RGB
	unsigned char * data;
	FILE *file;
	fopen_s(&file, file_name, "rb");
	if (!file) { printf("Image could not be opened\n"); return 0; }

	if (fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		return false;
	}

	if (header[0] != 'B' || header[1] != 'M') {
		printf("Not a correct BMP file\n");
		return 0;
	}

	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	// Algunos archivos BMP tienen un mal formato, así que adivinamos la información faltante
	if (imageSize == 0)    imageSize = width*height * 3; // 3 : un byte por cada componente Rojo (Red), Verde (Green) y Azul(Blue)
	if (dataPos == 0)      dataPos = 54; // El encabezado del BMP está hecho de ésta manera

										 // Se crea un buffer
	data = new unsigned char[imageSize];

	// Leemos la información del archivo y la ponemos en el buffer
	fread(data, 1, imageSize, file);

	//Todo está en memoria ahora, así que podemos cerrar el archivo
	fclose(file);

	// Se Crea una textura OpenGL
	GLuint textureID;
	glGenTextures(1, &textureID);

	// Se "Ata" la nueva textura : Todas las futuras funciones de texturas van a modificar esta textura
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Se le pasa la imagen a OpenGL
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1024, 1024, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);	


	return textureID;
}


// Carga basica de archivos *.OBJ
bool Utilidades::loadOBJ(const char* path, std::vector<glm::vec3>& out_vertices, std::vector<glm::vec2>& out_UVs, std::vector<glm::vec3>& out_normals, std::vector<unsigned int>& indices)
{
	FILE* file;
	fopen_s(&file, path, "r");

	char linea[128];

	while (true)
	{
		if (fgets(linea, 128, file) == NULL)
			break;

		if (linea[0] == 'v')
		{
			if (linea[1] == 'n')
			{
				glm::vec3 vertex;
				fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
				out_normals.push_back(vertex);
			}
			else if (linea[1] == 't')
			{
				glm::vec2 vertex;
				fscanf(file, "%f %f\n", &vertex.x, &vertex.y);
				out_UVs.push_back(vertex);
			}
			else
			{
				glm::vec3 vertex;
				scanf(linea, "%f %f %f", &vertex.x, &vertex.y, &vertex.z);
				out_vertices.push_back(vertex);
			}
			
		}
		else if (linea[0]=='f')
		{
			unsigned int vertexindex[4], uvindex[4], normalindex[4];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d\n",
				&vertexindex[0], &uvindex[0], &normalindex[0],
				&vertexindex[1], &uvindex[1], &normalindex[1],
				&vertexindex[2], &uvindex[2], &normalindex[2],
				&vertexindex[3], &uvindex[3], &normalindex[3]);

			indices.push_back(vertexindex[0]-1);
			indices.push_back(vertexindex[1]-1);
			indices.push_back(vertexindex[2]-1);
			indices.push_back(vertexindex[0]-1);
			indices.push_back(vertexindex[2]-1);
			indices.push_back(vertexindex[3]-1);
		}
	}

	return true;
}
