#pragma once
#ifndef SCENE_HPP
#define SCENE_HPP

#include "Form.hpp"
#include "Toys.hpp"
#include "Frame.hpp"


class Scene
{
public:

	bool TryPutToy(Toys& toy, Form hole)
	{
		if(toy == hole)
	}



private:

	bool operator==()

	void CreateHand(int difficulty)
	{

		
		if (difficulty == 1)
		{
			_size = 4;
		}
		else if (difficulty == 2)
		{
			_size = 6;
		}
		else if (difficulty == 3)
		{
			_size = 8;
		}


		for (int i = 0; i < _size; i++)
		{
			int randNum = rand() + 1 % difficulty+1;

			if (randNum == 1)
			{
				_hand.push_back(Form(Form::Shapes::circle));
			}
			else if (randNum == 2)
			{
				_hand.push_back(Form(Form::Shapes::square));
			}
			else if (randNum == 3)
			{
				_hand.push_back(Form(Form::Shapes::star));
			}
			else
			{
				_hand.push_back(Form(Form::Shapes::triangle));
			}
			
		}

	}


	int _size;

	std::vector<Toys> _hand;

	Form forms[4] { Form(Form::Shapes::circle), Form(Form::Shapes::square), Form(Form::Shapes::star), Form(Form::Shapes::triangle) };

	Frame _holes[4] { Form(Form::Shapes::circle), Form(Form::Shapes::square), Form(Form::Shapes::star), Form(Form::Shapes::triangle) };

};

#endif //SCENE_HPP


