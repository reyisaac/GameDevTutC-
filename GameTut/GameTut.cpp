#include "pch.h"
#include <iostream>
#include "Engine/engine.h"
using namespace std;

int main()
{
    cout << "Hello World!\n"; 

	Engine engine;

	while (true)
	{
		engine.Update();
		engine.Render();
	}

	return 0;
}


