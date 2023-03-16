#include "Rational.h"

void Rational::print() {
    std::cout << numerator << "/" << denominator << std::endl;
}

//Default to zero
Rational::Rational() {
    numerator = 0;
    denominator = 1;
}


Rational::Rational(int num, int denom) {
    numerator = num;
    denominator = denom;

    simplify();
}

int Rational::get_numerator() const {
    return numerator;
}

int Rational::get_denominator() const {
    return denominator;
}

bool Rational::is_zero() {
    return numerator == 0;
}

Rational Rational::operator- () {
    return Rational(-numerator, denominator);
}

Rational Rational::reciprocal() {
    return Rational(denominator, numerator);
}

Rational& Rational::operator+= (Rational const &rhs) {

    this->numerator = this->numerator*rhs.denominator + rhs.numerator*this->denominator;
    this->denominator *= rhs.denominator;

    this->simplify();
    return *this;
}

//can probably rewrite this in terms of += and negation operators
Rational& Rational::operator-= (Rational const &rhs) {

    this->numerator = this->numerator*rhs.denominator - rhs.numerator*this->denominator;
    this->denominator *= rhs.denominator;

    this->simplify();
    return *this;
}

Rational& Rational::operator*= (Rational const &rhs) {
    this->numerator *= rhs.numerator;
    this->denominator *= rhs.denominator;

    this->simplify();
    return *this;
}

Rational& Rational::operator/= (Rational const &rhs) {
    this->numerator *= rhs.denominator;
    this->denominator *= rhs.numerator;

    this->simplify();
    return *this;
}


void Rational::simplify() {

    //all numbers should have a positive denominator
    if(denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }

    //zero = 0/1
    if(numerator == 0) {
        denominator = 1;
        return;
    }

    //infinity = 1/0
    if(denominator == 0) {
        if(numerator == 0)
            numerator = 1;

        numerator /= std::abs(numerator);
        return;
    }

    //numerator and denominator should not have any common factors
    int g = std::gcd(numerator, denominator);

    numerator /= g;
    denominator /= g;

    return;
}
