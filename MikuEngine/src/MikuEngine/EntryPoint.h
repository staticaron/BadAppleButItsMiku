#include "Application.h"
#include "Core.h"

extern MikuEngine::Application* MikuEngine::EntryPoint();

int main()
{
	std::cout << "Welcome to MikuEngine!" << std::endl;

	MikuEngine::EntryPoint();

	return 0;
}