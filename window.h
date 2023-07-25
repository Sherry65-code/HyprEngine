// Standard Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Include GLEW.
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

int createWindow(char *window_name, int window_width, int window_height) {
	glewExperimental = true;
	if ( !glfwInit() ) {
		fprintf(stderr, "Failed to Initialize GLFW!\n");
		return -1;
	}

	// 4x antialiasing
	glfwWindowHint(GLFW_SAMPLES, 4);
	
	// OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// To make MacOS Happy (Not important)
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// We don't want old OpenGL
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	// In the accompanying source code, this variable is global for simplicity
	GLFWwindow* window;
	window = glfwCreateWindow(window_width, window_height, window_name, NULL, NULL);

	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window.");
		glfwTerminate();
		return -1;
	}

	// Initialize GLEW
	glfwMakeContextCurrent(window);

	// Needed in core profile
	glewExperimental = true;
	
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW!\n");
		return -1;
	}
	
	// To ensure that the program can listen to the esc key
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	do {
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw nothing

		// Swap Buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	
	}
	
	// Check for the esc key is pressed and if yes then close the window
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}
