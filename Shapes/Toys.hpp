
#pragma once
#ifndef TOYS_HPP
#define TOYS_HPP

#include "Header.hpp"
#include "Frame.hpp"
#include "Form.hpp"

class Toys
{
public:
	Toys(const Form& form) :_form(std::make_unique<Form>(form)) {}

	const Form& GetShape()const
	{
		return *_form;
	}

	std::string GetFormString()
	{
		return _form->GetName();
	}

	bool IsSame(const Toys& other)const
	{
		return this == &other;
	}


private:
	std::unique_ptr<Form> _form;
};

#endif // !TOYS_HPP



