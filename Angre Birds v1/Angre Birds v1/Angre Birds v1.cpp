// Angre Birds v1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#include <GL\glew.h>

#include <GLFW\glfw3.h>

#include <glm\glm.hpp>


int main()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // OPENGL 4
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // No deberia ser necesario---borrar
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //No queremos el antiguo OPENGL

																   // Abrir una ventana y crear el contexto OPENGL
	GLFWwindow* window; // (Tiene que ser global)
	window = glfwCreateWindow(1024, 768, "Angry Birds 1", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Fallo al crear una ventana GLFW. Si tienes una GPU Intel, no es compatible con las versiones 3+\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); // Iniciar GLEW
	glewExperimental = true; // Necesario en CORE
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Fallo al inciar GLEW\n");
		return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	do {
		// Draw nothing, see you in tutorial 2 !

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Revisar si escape para salir
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

    return 0;
}

