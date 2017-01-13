#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main(void)
{
	GLFWwindow* window;
	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();

	float vertices[] = {
		0.0f, 0.5f,
		0.5f, -0.5f,
		-0.5f, -0.5f
	};

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	const GLchar* vertex_shader_src =
		"#version 150\n"
		"in vec2 position;"
		"void main()"
		"{"
		"	gl_Position = vec4(position, 0.0, 1.0);"
		"}";
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex_shader_src, NULL);
	glCompileShader(vertexShader);
	GLint test;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &test);
	if (test != GL_TRUE) {
		printf("error vertex shader\n");
		char buffer[512];
		glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
		printf(buffer);
		printf("\n");
	}

	const GLchar* frag_shader_src = "#version 150\n"
		"out vec4 outColor;"
		"void main()"
		"{"
		"	outColor = vec4(1.0, 1.0, 1.0, 1.0);"
		"}";
	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, &frag_shader_src, NULL);
	glCompileShader(fragShader);
	GLint test_frag;
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &test_frag);
	if (test_frag != GL_TRUE) {
		printf("error fragment shader\n");
	}

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragShader);

	glBindFragDataLocation(shaderProgram, 0, "outColor"); // not strictly needed

	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);


	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
