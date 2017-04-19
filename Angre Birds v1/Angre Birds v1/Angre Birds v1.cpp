// Angre Birds v1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Esfera.h"
#include "Iniciador.h"
#include "Tetra.h"
#include "Utilidades.h"
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

	//color azul oscuro
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexarrayID;
	glGenVertexArrays(1, &VertexarrayID);
	glBindVertexArray(VertexarrayID);

	GLuint programID = Utilidades::LoadShaders("vertexshader.txt","fragmentshader.txt");

	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	GLuint MID = glGetUniformLocation(programID, "M");
	GLuint VID = glGetUniformLocation(programID, "V");
	GLuint lightID = glGetUniformLocation(programID, "LightPosition_worldspace");
	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(0, -50, 10), // Camera is at (X,Y,Z), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);

	glm::mat4 VP = Projection * View;
	
	glm::vec3 light(20.0, 20.0, 20.0);

	Base B;
	Esfera T;
	Tetra R(glm::vec3(2.0,2.0,2.0));

	//vector de objetos base
	std::vector<Base*> v;
	v.push_back(&B);
	v.push_back(&T);
	v.push_back(&R);
	Iniciador::iniciar_base();
	Iniciador::iniciar(&T);
	Iniciador::iniciar(&R);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	do {
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glUseProgram(programID);
		glUniformMatrix4fv(VID, 1, GL_FALSE, &(View)[0][0]);
		glUniform3f(lightID, light[0],light[1],light[2]);
		for each (auto var in v)
		{
			glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &(VP*var->model_matrix)[0][0]);
			glUniformMatrix4fv(MID, 1, GL_FALSE, &(var->model_matrix)[0][0]);
			var->mover();
			var->rotar();
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, Iniciador::buffer_vertex[var->id()]);
			glVertexAttribPointer(
				0,                  // atributo 0. No hay razón particular para el 0, pero debe corresponder en el shader.
				3,                  // tamaño
				GL_FLOAT,           // tipo
				GL_FALSE,           // normalizado?
				0,                    // Paso
				(void*)0            // desfase del buffer
			);
			
			//glDrawArrays(GL_TRIANGLES, 0, Iniciador::buffer_trian[var->id()] * 3); // Empezar desde el vértice 0S; 3 vértices en total -> 1 triángulo
			

			// 2do atributo del buffer : coordenaras de textura
			glEnableVertexAttribArray(1);
			glBindBuffer(GL_ARRAY_BUFFER, Iniciador::buffer_UV[var->id()]);
			glVertexAttribPointer(
				1,                                // Atributo. No hay razón especial para el 1, pero debe corresponder al número en el shader.
				2,                                // tamaño
				GL_FLOAT,                         // tipo
				GL_FALSE,                         // normalizado?
				0,                                // corrimiento
				(void*)0                          // corrimiento de buffer
			);

			//3er atributo del buffer: normales!!
			glEnableVertexAttribArray(2);
			glBindBuffer(GL_ARRAY_BUFFER, Iniciador::buffer_normal[var->id()]);
			glVertexAttribPointer(
				2,                  // atributo 2. No hay razón particular para el 0, pero debe corresponder en el shader.
				3,                  // tamaño
				GL_FLOAT,           // tipo
				GL_FALSE,           // normalizado?
				0,                    // Paso
				(void*)0            // desfase del buffer
			);

			// Dibujar el triángulo !
			glBindTexture(GL_TEXTURE_2D, Iniciador::buffer_text[var->id()]);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Iniciador::buffer_indice[var->id()]);
			glDrawElements(GL_TRIANGLES, Iniciador::buffer_trian[var->id()]*3, GL_UNSIGNED_INT, (void*)0);

			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);
			glDisableVertexAttribArray(2);
		}

		
		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Revisar si escape para salir
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

    return 0;
}

