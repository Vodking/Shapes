
#pragma once

#ifndef FORM_HPP
#define FORM_HPP

#include "Header.hpp"

class Form
{
public:
	enum class Shapes
	{
		circle,
		triangle,
		square,
		star
	};

	Form(Shapes shape)
	{
		_shape = shape;
		switch (shape)
		{
		case Shapes::circle:
			_name = "circle";
			break;
		case Shapes::triangle:
			_name = "triangle";
			break;
		case Shapes::square:
			_name = "square";
			break;
		case Shapes::star:
			_name = "star";
			break;
		}	
	}

	std::string GetName()const
	{
		return _name;
	}

	Shapes GetShape()const
	{
		return _shape;
	}

	virtual bool operator ==(const Form& rso)const
	{
		return _shape == rso._shape;
	}

	virtual bool IsEqual(const Form& rso)const
	{
		return *this == rso;
	}
private:
	Shapes _shape;
	std::string _name;
};
#endif //FORM_HPP
