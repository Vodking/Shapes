#include "Header.hpp"
#include "Scene.hpp"
#include "SceneDirector.hpp"
int main()
{
	std::srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SceneDirector director;
	director.Menu();
}