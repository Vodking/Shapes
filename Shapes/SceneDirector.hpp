#pragma once
#ifndef SCENEDIRECTOR_HPP
#define SCENEDIRECTOR_HPP

#include "Scene.hpp"

class SceneDirector
{
public:

	void Menu()
	{
		int input;
		while (true)
		{
			std::cout << "Добро пожаловать в сравнилкинс\n";
			std::cout << "1 - начать игру(лёгкая), 2 - начать игру(средняя), 3 - начать игру(сложная) 4 - выйти";
			do
			{
				std::cin >> input;
				if (input < 0 || input > 4)
				{
					std::cout << "Ввод вне диапазона!";
				}
				else
				{
					break;
				}
			} while (true);

			if (input == 4)
			{
				break;
			}
			else if (input == 1)
			{
				Game(1);
			}
			else if (input == 2)
			{
				Game(2);
			}
			else if (input == 3)
			{
				Game(3);
			}
		}
		

		
	}

private:
	std::vector<Toys> _hand;
	std::vector<Frame> _holes;
	
	void Game(int difficulty)
	{
		int input;
		Scene scene(difficulty);
		_hand = scene.GetHand();
		_holes = scene.GetHoles();

		while (_hand.size() != 0)
		{
			std::cout << "Ход " << scene.GetCycle();
			PrintHand();

			std::cout << "Текущая игрушка: " << _hand.at(_hand.size() - 1).GetFormString() << "\n";

			PrintHoles();

			do
			{
				std::cout << "Введите номер отверстия: ";
				std::cin >> input;
				if (input >= _holes.size() || input < 0)
				{
					std::cout << "\nВвод вне диапазона!\n";
				}
				else
				{
					break;
				}
			} while (true);
			if (scene.TryPutToy(_hand.at(_hand.size() - 1), _holes.at(input)))
			{
				std::cout << "\nПолучилось!\n";
			}
			else
			{
				std::cout << "\nНе получилось...\n";
			}
		}

		


	}

	void PrintHand()
	{
		std::cout << "Ваша рука: ";
		for (int i = 0; i < _hand.size(); i++)
		{
			std::cout << _hand[i].GetFormString() << " ";
		}
		std::cout << "\n";
	}

	void PrintHoles()
	{
		std::cout << "Отверстия: ";
		for (int i = 0; i < _holes.size(); i++)
		{
			std::cout << _holes[i].GetFormString() << " ";
		}
		std::cout << "\n";
	}
};

#endif // !SCENEDIRECTOR_HPP



