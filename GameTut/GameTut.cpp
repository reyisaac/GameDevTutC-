#include "pch.h"
#include <iostream>
#include "Engine/engine.h"
#include <string>
using namespace std;

int main()
{
	Engine engine;
	char buffer[80];
	strcpy_s(buffer, "GameTut");

	engine.Initialize(buffer);
	while (true)
	{
		engine.Update();
		engine.Render();
	}

	return 0;
}


