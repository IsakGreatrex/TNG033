/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <cmath>
#include <iomanip>

// ADD implementation of the member functions for class Polynomial

Polynomial::Polynomial(const std::vector<double>& V)
{
	//std::vector<Polynomial>coefficientValues{ V };

	for (double i : V) {
		coefficientValues.push_back(i);
	}
}

const double& Polynomial::operator[](int x) const {
	return coefficientValues[x];
}

double& Polynomial::operator[](int x) {
	return coefficientValues[x];
}

double Polynomial::operator()(const double x) const {
	double result = 0.0;
	for (int i = 0; i < this->coefficientValues.size(); i++) {
		result += coefficientValues[i] * pow(x, i);
	}
	return result;
}

Polynomial Polynomial::operator+=(const Polynomial& Po) {
	int minLength = std::min(coefficientValues.size(), Po.coefficientValues.size());
	for (int i = 0; i < minLength; i++) {
		this->coefficientValues[i] += Po.coefficientValues[i];
	}
	if (this->coefficientValues.size() < Po.coefficientValues.size()) {
		for (int i = minLength; i < Po.coefficientValues.size(); i++) {
			coefficientValues.push_back(Po.coefficientValues[i]);
		}
	} else {
			// Do nothing

	}
	return *this;
}

/*Polynomial operator+(Polynomial p1, const Polynomial& p2) {
	int minLen = math.min(p1.coefficientValues.size(), p2.coefficentValues.size());
	return p1 += p2;
}*/


Polynomial operator+(const Polynomial& p1, const Polynomial& p2){
	int minLen = std::min(p1.coefficientValues.size(), p2.coefficientValues.size());
	Polynomial summa{ p1 };
	for (int i = 0; i < minLen; i++){
		summa.coefficientValues[i] += p2.coefficientValues[i];
	}
	if (summa.coefficientValues.size() <  p2.coefficientValues.size()) {
		for (int i = minLen; i < p2.coefficientValues.size(); i++){
			summa.coefficientValues.push_back(p2.coefficientValues[i]);
		}
	}


	return summa;   // copy constructor is called

}

void Polynomial::display(std::ostream& os) const {
	os << std::fixed << std::setprecision(2);
	os << coefficientValues[0];	//Inte fullständigt
	for (size_t i = 1; i < coefficientValues.size(); i++)
	{
		if (coefficientValues[i] < 0) {
			os << " - " << std::abs(coefficientValues[i]) << " * X^" << i;
		}
		else {
			os << " + " << coefficientValues[i] << " * X^" << i;
		}
	}
}

Polynomial* Polynomial::clone()const {
	return new Polynomial{ *this };
}
