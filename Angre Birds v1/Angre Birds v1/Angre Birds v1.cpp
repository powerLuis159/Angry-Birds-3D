// Angre Birds v1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Objects.h"
#include "Esfera.h"
#include "Iniciador.h"
//#include "Tetra.h"
#include "Utilidades.h"

size_t angryBird = 1;
double ang = 0.1;

bool _window = true;

Objects objs;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		_window = false;	// end the main loop
	}
	if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT )) {
		glm::vec3 v(0.0, 0.5, 0.0);
		objs.move(angryBird, v);
	}
	if (key == GLFW_KEY_DOWN&& (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		glm::vec3 v(0.0, -0.5, 0.0);
		objs.move(angryBird, v);
	}
	if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		glm::vec3 v(-0.5, 0.0, 0.0);
		objs.move(angryBird, v);
	}
	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		glm::vec3 v(0.5, 0.0, 0.0);
		objs.move(angryBird, v);
	}
	if (key == GLFW_KEY_HOME&& (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		glm::vec3 v(-1.0, 0.0, 0.0);
		objs.vec[angryBird]->rotar(ang,v);
	}
	if (key == GLFW_KEY_END&& (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		glm::vec3 v(1.0, 0.0, 0.0);
		objs.vec[angryBird]->rotar(ang,v);
	}
}

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
	GLuint camID = glGetUniformLocation(programID, "camera_worlspace");
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

	// Camera matrix
	glm::vec3 cam_pos(0.0, -40, 30);

	glm::mat4 View = glm::lookAt(
		cam_pos, // Camera is at (X,Y,Z), in World Space4
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 1)  // Head is up (set to 0,-1,0 to look upside-down)
	);

	glm::vec3 light(0.0, 0.0, 0.0);

	glm::mat4 VP = Projection * View;
	
	objs.add(BASE  , glm::vec3(0.0, 0.0, 0.0));		// Base vacia
	objs.add(SPHERE, glm::vec3(0.0, -30.0, 15.0));
	objs.add(SPHERE, glm::vec3(10.0, 20.0, 15.0));
	objs.add(SPHERE, glm::vec3(-10.0 , 20.0, 25.0));
	objs.add(SPHERE, glm::vec3(1.5, -5.0, 10.0));
	objs.add(SPHERE, glm::vec3(0.0, 0.0, 10.0));
	objs.add(SPHERE, glm::vec3(-10.0, 5.0, 10.0));
	//objs.add(SPHERE, glm::vec3(0, 0.0, 1.0));

	Iniciador::iniciar_base();
	
	for(int i=1; i<objs.vec.size(); i++)
		Iniciador::iniciar(objs.vec[i]);

	//objs.vec[angryBird]->addForce(glm::vec3(0.0, 100.0, 200.0));
	objs.vec[angryBird]->push(glm::vec3(0.0, 0.3, 0.0));
	while(_window) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(programID);

		objs.step();
		glUniformMatrix4fv(VID, 1, GL_FALSE, &(View)[0][0]);
		glUniform3f(lightID, light[0], light[1], light[2]);
		glUniform3f(camID, cam_pos[0], cam_pos[1], cam_pos[2]);
		for each (auto var in objs.vec)
		{
			//var->applyImpulse();
			glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &(VP*var->model_matrix)[0][0]);
			glUniformMatrix4fv(MID, 1, GL_FALSE, &(var->model_matrix)[0][0]);
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
			

			// 2do atributo del buffer : colores
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

			// 3do atributo del buffer : colores
			glEnableVertexAttribArray(2);
			glBindBuffer(GL_ARRAY_BUFFER, Iniciador::buffer_normal[var->id()]);
			glVertexAttribPointer(
				2,                                // Atributo. No hay razón especial para el 1, pero debe corresponder al número en el shader.
				3,                                // tamaño
				GL_FLOAT,                         // tipo
				GL_FALSE,                         // normalizado?
				0,                                // corrimiento
				(void*)0                          // corrimiento de buffer
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
		glfwSetKeyCallback(window, key_callback);
		glfwPollEvents();
		
	} // Revisar si escape para salir
	//while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
	

    return 0;
}


