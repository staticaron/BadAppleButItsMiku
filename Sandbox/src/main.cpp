#include <iostream>

#include "MikuEngine.h"

MikuEngine::Application* MikuEngine::EntryPoint()
{
	MikuEngine::Application* app = new MikuEngine::Application();

	app->Run();

	return app;
}
