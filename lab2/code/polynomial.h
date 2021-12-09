/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>

#include "expression.h"

class Polynomial : public Expression {
	// ADD CODE
public:
	Polynomial(const std::vector<double>& V);	//Gör vektorer till polynom

	Polynomial(const double& v) {		//Gör doubles till polynom
		coefficientValues.push_back(v);
	}

	const double& operator[](int x) const;
	double& operator[](int x);

	double operator()(const double x) const override;

	Polynomial operator+=(const Polynomial& Po);	//Tar in ett polynom

	friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2);

	void display(std::ostream& os = std::cout) const override;

	Polynomial* clone() const override;


private: 
	std::vector<double> coefficientValues;
};


