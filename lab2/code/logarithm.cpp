/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"
#include <vector>
#include <iomanip>

// ADD implementation of the member functions for class Logarithm

//Logarithm::Logarithm(const Logarithm& L) {	//Copy constructorn
//	base = L.base;
//	c1 = L.c1;
//	c2 = L.c2;
//	e = L.e->clone();
//}

double Logarithm::operator()(const double a) const {

	double result = c1 + c2 * log10((*e)(a));
	return result;

	//return c1 + c2 * log10((*e)(a));
}

Logarithm& Logarithm::operator=(Logarithm& Lo) {
	std::swap(base, Lo.base);
	std::swap(c1, Lo.c1);
	std::swap(c2, Lo.c2);
	std::swap(e, Lo.e);

	return *this;
}

//Logarithm::Logarithm() {	//Base constructor
//	base = 2;
//	c1 = 0;
//	c2 = 1;
//	e = new Polynomial(std::vector<double>{ 0, 1 });
//}

//Logarithm::Logarithm(Expression& expr, double constant1, double constant2, int b){	//constructor som har parametrar
//	base = b;
//	c1 = constant1;
//	c2 = constant2;
//	//e = &expr;
//	e = expr.clone();
//}




void Logarithm::set_base(int b) {
	base = b;
}

void Logarithm::display(std::ostream& os) const {
	//0.00 + 1.00 * Log_2(0.00 + 1.00 * X ^ 1
	os << std::fixed << std::setprecision(2);
	if (c1 < 0) {
		os << " - " << std::abs(c1);
	}
	else {
		os << c1;
	}

	if (c2 < 0) {
		os << " - " << std::abs(c2);
	}
	else {
		os << " + " << c2;
	}

	os << " * Log_" << base << "( ";
	e->display(os);
	os << " )";

	
}

Logarithm* Logarithm::clone()const{
	return new Logarithm{ *this };
}
