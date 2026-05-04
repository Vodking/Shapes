
#pragma once

//#pragma warning(disable : 4430)

#ifndef FRAME_HPP
#define FRAME_HPP

#include "Header.hpp"
#include "Form.hpp"
#include "Toys.hpp"

class Frame
{
public:
	Frame(const Form& form) :_form(std::make_unique<Form>(form)) {}// янгдюрэ йнмярпсйрнп он слнквюмхч х йнмярпсйрнп йнохпнбюмхъ дкъ FRAME х TOYS

	Frame()
	{
		_form = std::make_unique<Form>(Form(Form::Shapes::circle));
	}

	Frame(const Frame& frame)
	{
		_form = std::make_unique<Form>(frame.GetShape());
	}

	Frame& operator =(const Frame& other)
	{
		_form = std::make_unique<Form>(other.GetShape());
		return *this;
	}


	bool IsSame(const Frame& other)
	{
		return this == &other;
	}

	const Form& GetShape()const
	{
		return *_form;
	}

	std::string GetFormString()
	{
		return _form->GetName();
	}

	bool IsFit(const Form& form)const
	{
		return _form->IsEqual(form);
	}

	

private:
	std::unique_ptr<Form> _form;
};


#endif // !FRAME_HPP



