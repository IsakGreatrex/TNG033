/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

constexpr double Epsilon = 1.0e-5;

class Expression {
public:
    // Destructor
    virtual ~Expression() {
        --count_expressions;
    }

    // ADD OTHER MEMBER FUNCTIONS

    // Return number of existing instances of class Expression
    // Used only for debug purposes
    static std::size_t get_count_expressions();

    virtual double operator()(const double a) const = 0;

    bool isRoot(const double x) const;

    virtual void display(std::ostream& os) const = 0;

    virtual Expression* clone() const = 0;

protected:
    // Default constructor
    Expression() {
        ++count_expressions;
    }

    // Copy constructor
    Expression(const Expression&) {
        ++count_expressions;
    }

    // Total number of existing expressions -- to help to detect bugs in the code
    static std::size_t count_expressions;

    friend std::ostream& operator << (std::ostream & os, const Expression & E);
};
