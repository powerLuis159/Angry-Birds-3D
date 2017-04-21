// Angre Birds v1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Objects.h"
#include "Iniciador.h"
#include "Utilidades.h"
#include "Niveles.h"
size_t angryBird = 3;
double ang = 0.1;

bool _window = true;

Objects objs;

glm::vec3 impulse(0.0, 0.5, 0.2);
float iStep = 0.03;

glm::vec3 cam(0.0, 0.0, 50.0);
glm::vec3 camVal(-40.0, -40.0, 30.0);
float angleX = 3.1415/2;
float angleY = 0.0;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		_window = false;	// end the main loop
	}
	if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT )) {
		impulse[1] += iStep;
		objs.vec[1]->traslate(glm::vec3(0.0, -25.0, 1.0));
		objs.vec[2]->traslate(glm::vec3(0.0, -25.0, 1.0));
		
		float mult = 1;
		objs.vec[1]->mover(impulse*(mult * 5));
		objs.vec[2]->mover(impulse*(mult * 10));
	}
	if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		impulse[1] -= iStep;
		objs.vec[1]->traslate(glm::vec3(0.0, -25.0, 1.0));
		objs.vec[2]->traslate(glm::vec3(0.0, -25.0, 1.0));

		float mult = 1;
		objs.vec[1]->mover(impulse*(mult * 5));
		objs.vec[2]->mover(impulse*(mult * 10));
	}
	if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		impulse[0] -= iStep;
		objs.vec[1]->traslate(glm::vec3(0.0, -25.0, 1.0));
		objs.vec[2]->traslate(glm::vec3(0.0, -25.0, 1.0));

		float mult = 1;
		objs.vec[1]->mover(impulse*(mult * 5));
		objs.vec[2]->mover(impulse*(mult * 10));
	}
	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		impulse[0] += iStep;
		objs.vec[1]->traslate(glm::vec3(0.0, -25.0, 1.0));
		objs.vec[2]->traslate(glm::vec3(0.0, -25.0, 1.0));

		float mult = 1;
		objs.vec[1]->mover(impulse*(mult * 5));
		objs.vec[2]->mover(impulse*(mult * 10));
	}
	if (key == GLFW_KEY_HOME && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		impulse[2] += iStep;
		objs.vec[1]->traslate(glm::vec3(0.0, -25.0, 1.0));
		objs.vec[2]->traslate(glm::vec3(0.0, -25.0, 1.0));

		float mult = 1;
		objs.vec[1]->mover(impulse*(mult * 5));
		objs.vec[2]->mover(impulse*(mult * 10));
	}
	if (key == GLFW_KEY_END && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		impulse[2] -= iStep;
		objs.vec[1]->traslate(glm::vec3(0.0, -25.0, 1.0));
		objs.vec[2]->traslate(glm::vec3(0.0, -25.0, 1.0));

		float mult = 1;
		objs.vec[1]->mover(impulse*(mult * 5));
		objs.vec[2]->mover(impulse*(mult * 10));
	}
	if (key == GLFW_KEY_SPACE && (action == GLFW_PRESS)) {
		objs.vec[angryBird]->push( impulse );
		objs.vec[1]->traslate(glm::vec3(0.0, -100.0, 1.0));
		objs.vec[2]->traslate(glm::vec3(0.0, -100.0, 1.0));
	}
	if (key == GLFW_KEY_LEFT_CONTROL && (action == GLFW_PRESS)) {
		objs.vec[angryBird]->reset();
		objs.vec[angryBird]->traslate(glm::vec3(0.0, -25.0, 1.0));

		objs.vec[1]->traslate(glm::vec3(0.0, -25.0, 1.0));
		objs.vec[2]->traslate(glm::vec3(0.0, -25.0, 1.0));
		
		float mult = 1;
		objs.vec[1]->mover(impulse*(mult * 5));
		objs.vec[2]->mover(impulse*(mult * 10));
	}
	if (key == GLFW_KEY_TAB && (action == GLFW_PRESS)) {
		glm::vec3 c = objs.vec[angryBird]->center;
		float mult = 5.0;
		objs.vec[angryBird]->mover(objs.vec[angryBird]->linearVelocity * mult);
		objs.add(SPHERE,c);
		objs.vec[objs.vec.size() - 1]->linearVelocity = objs.vec[angryBird]->linearVelocity;
		objs.vec[objs.vec.size() - 1]->linearVelocity[0] += 0.5;
		objs.vec[objs.vec.size() - 1]->mover(objs.vec[objs.vec.size() - 1]->linearVelocity * mult);
		objs.add(SPHERE, c);
		objs.vec[objs.vec.size() - 1]->linearVelocity = objs.vec[angryBird]->linearVelocity;
		objs.vec[objs.vec.size() - 1]->linearVelocity[0] -= 0.5;
		objs.vec[objs.vec.size() - 1]->mover(objs.vec[objs.vec.size() - 1]->linearVelocity * mult);
	}

	if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		angleX += 0.05;
		cam[0] = camVal[0]*sin(angleX);
	}
	if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		angleX -= 0.05;
		cam[0] = camVal[0] *sin(angleX);
	}
	if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		angleY += 0.05;
		cam[1] = camVal[1] * cos(angleY);
	}
	if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		angleY -= 0.05;
		cam[1] = camVal[1] * sin(angleY);
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

	
	glm::mat4 View = glm::lookAt(
		cam, // Camera is at (X,Y,Z), in World Space4
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 0, 1)  // Head is up (set to 0,-1,0 to look upside-down)
	);

	glm::vec3 light(0.0, 0.0, 50.0);

	glm::mat4 VP = Projection * View;
	
	
	Niveles mijuego;
	objs.vec = mijuego.nivel(0);

	Iniciador::iniciar_base();
	
	for(int i=1; i<objs.vec.size(); i++)
		Iniciador::iniciar(objs.vec[i]);
	Iniciador::buffer_text[0] = mijuego.get_escenario(0);
	//objs.vec[angryBird]->addForce(glm::vec3(0.0, 100.0, 200.0));
	
	while(_window) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(programID);

		objs.step();
		glUniformMatrix4fv(VID, 1, GL_FALSE, &(View)[0][0]);
		glUniform3f(lightID, light[0], light[1], light[2]);
		glUniform3f(camID, cam[0], cam[1], cam[2]);

		View = glm::lookAt(
			cam, // Camera is at (X,Y,Z), in World Space4
			glm::vec3(0, 0, 0), // and looks at the origin
			glm::vec3(1, 1, 1)  // Head is up (set to 0,-1,0 to look upside-down)
		);
		
		VP = Projection * View;

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