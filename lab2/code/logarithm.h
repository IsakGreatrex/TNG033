/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>
#include "expression.h"
#include "polynomial.h"

class Logarithm : public Expression {
public:
	Logarithm()
		: base{2}, c1{0.0}, c2{1.0}, e{ new Polynomial(std::vector<double>{ 0.0, 1.0 }) } {} //Default constructor

	Logarithm(Expression& expr, const double constant1, const double constant2, const int b)
		: base{b}, c1{constant1}, c2{constant2}, e{ expr.clone() } {}	//explicit för att kompilatorn ska prioritera denna

	Logarithm(const Logarithm& L)	//Member initializer list
		: base{L.base}, c1{L.c1}, c2{L.c2}, e{ L.e->clone() } {}

	~Logarithm() {	//Destructor
		delete e;
		e = nullptr;
	}

	double operator()(const double a) const override;

	void set_base(int b);

	void display(std::ostream& os = std::cout) const override;

	Logarithm* clone() const override;

	Logarithm& operator=(Logarithm& Lo);


private:
	int base;
	double c1;
	double c2;
	Expression* e;

};
