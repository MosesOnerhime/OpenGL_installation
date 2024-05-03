#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main()
{
	glfwInit();

	// Tell GLFW hwat version of OpenGL we are using
	// In this case OpenGl 3.3 is being used
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGLInstallation", NULL, NULL);
	
	// Error Check if the window fails to create
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL
	gladLoadGL();

	// Specify the viewport of OpenGl in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 800, 800);

	// Specify the color of the background
	glClearColor(1.55f, 0.38f, 1.82f, 1.0f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);

	// Main while loop
	while (!glfwWindowShouldClose(window)) {

		// Takes care of all GLFW events
		glfwPollEvents();
	}

	//Delete window before ending the progress
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the progress
	glfwTerminate();
	
	return 0;
}