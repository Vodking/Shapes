#pragma once
#ifndef SCENE_HPP
#define SCENE_HPP

#include "Form.hpp"
#include "Toys.hpp"
#include "Frame.hpp"


class Scene
{
public:

	Scene(int difficulty)
	{
		CreateHand(difficulty);
		_cycle = 0;
		actionTook = false;
	}

	bool TryPutToy(Toys& toy, Frame& hole)
	{
		_cycle++;
		if (toy.GetForm() ==  hole.GetForm())
		{
			for (int i = 0; i < _hand.size(); i++)
			{
				if (toy.IsSame(_hand[i]))
				{
					_hand.erase(_hand.begin() + i);
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	std::vector<Toys>& GetHand()
	{
		return _hand;
	}

	std::vector<Frame>& GetHoles()
	{
		return _holes;
	}

	int GetCycle()
	{
		return _cycle;
	}

	Toys& GetCurrent()
	{
		return _hand.at(_hand.size()-1);
	}

	

private:
	bool actionTook;
	int _size, _cycle;
	int _holeSize;
	std::vector<Toys> _hand;
	std::vector<Frame> _holes;

	Form forms[4] { Form(Form::Shapes::circle), Form(Form::Shapes::square), Form(Form::Shapes::star), Form(Form::Shapes::triangle) };


	void CreateHand(int difficulty)
	{

		
		if (difficulty == 1)
		{
			_size = 4;
			_holeSize = 2;
			_holes.push_back(Form(Form::Shapes::circle));
			_holes.push_back(Form(Form::Shapes::square));
		}
		else if (difficulty == 2)
		{
			_size = 6;
			_holeSize = 3;
			_holes.push_back(Form(Form::Shapes::circle));
			_holes.push_back(Form(Form::Shapes::square));
			_holes.push_back(Form(Form::Shapes::star));
		}
		else if (difficulty == 3)
		{
			_size = 8;
			_holeSize = 4;
			_holes.push_back(Form(Form::Shapes::circle));
			_holes.push_back(Form(Form::Shapes::square));
			_holes.push_back(Form(Form::Shapes::star));
			_holes.push_back(Form(Form::Shapes::triangle));
		}


		for (int i = 0; i < _size; i++)
		{
			int randNum = rand() + 1 % _holeSize;

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


	

	//Frame _holes[4] { Form(Form::Shapes::circle), Form(Form::Shapes::square), Form(Form::Shapes::star), Form(Form::Shapes::triangle) };

};

#endif //SCENE_HPP


