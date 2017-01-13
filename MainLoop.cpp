#include "MainLoop.h"

MainLoop::MainLoop() {}

MainLoop::~MainLoop() {}

int MainLoop::mainLoop1() { 
	//string name;
	//cout << "string here: ";
	////cin >> name;

	float vertices[] = {
		0.0f,  0.5f, // Vertex 1 (X, Y)
		0.5f, -0.5f, // Vertex 2 (X, Y)
		-0.5f, -0.5f  // Vertex 3 (X, Y)
	};

	GLuint vbo;
	glGenBuffers(1, &vbo); // Generate 1 buffer

	return 0;
}


