#include "Header.hpp"
#include "Scene.hpp"
#include "SceneDirector.hpp"
int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	std::srand(time(NULL));


	SceneDirector director;
	director.Menu();
}