#include "Engine.h"

#include <iostream>

using namespace std;

int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window = NULL; //to use opengl

Engine::Engine()
{

}

Engine::~Engine()
{

}

bool Engine::Initialize(char* windowTitle)
{
	if (!glfwInit())
	{
		cout << "Error Initializing GLFW" << endl;
		return false;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);

	if (window == NULL)
	{
		cout << "Error creating window" << endl;
		return false;
	}

	//GLFW setup
	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCREEN_HEIGHT) / 2;
	int yPos = (mode->height - SCREEN_WIDTH) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	//GL Setup
	//Viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);

	//Alpha Blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

void Engine::Update()
{
	glfwPollEvents(); //upodate events by glfw
}

void Engine::Render()
{
	glClearColor(0, 1, 0, 1); //blue color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glfwSwapBuffers(window);

}