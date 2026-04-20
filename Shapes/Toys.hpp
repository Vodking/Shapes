
#pragma once
#ifndef TOYS_HPP
#define TOYS_HPP

#include "Header.hpp"
#include "Form.hpp"

class Toys
{
public:
	Toys(const Form& form) :_form(std::make_unique<Form>(form)) {}

	const Form& GetForm()const
	{
		return *_form;
	}

	bool IsSame(const Toys& other)const
	{
		return this == &other;
	}

private:
	std::unique_ptr<Form> _form;
};

#endif // !TOYS_HPP



