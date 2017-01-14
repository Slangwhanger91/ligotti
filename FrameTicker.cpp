#include "FrameTicker.h"

FrameTick::FrameTick() {}

FrameTick::~FrameTick() {}

void FrameTick::tick() { 
	float vertices[] = {
		-0.05f,  0.5f, // Vertex 1 (X, Y)
		-0.05f, -0.5f, // Vertex 2 (X, Y)
		-0.8f, -0.5f,  // Vertex 3 (X, Y)

		0.05f,  0.5f, // Vertex 1 (X, Y)
		0.05f, -0.5f, // Vertex 2 (X, Y)
		0.8f, -0.5f,  // Vertex 3 (X, Y)
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

}


