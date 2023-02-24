#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#pragma once

#include <vector>
#include <iostream>
#include <tuple>

class Polynomial
{
    public:
        Polynomial();
        Polynomial(std::vector<double>);

        int get_degree() const;
        int get_leading_coefficient() const;

        void print();

        bool is_zero() const;

        double operator()(double x);

        friend std::ostream& operator<<(std::ostream& out, Polynomial const& p)
        {
            for (auto i: p.coefficients)
            {
                out << i << ' ';
            }

            out << std::endl;
            return out;
        }

        friend bool operator==(const Polynomial& lhs, const Polynomial& rhs)
        {
            if(lhs.degree != rhs.degree)
                return false;

            for(int i = 0; i <= lhs.degree; i++)
            {
                if(lhs.coefficients[i] != rhs.coefficients[i])
                    return false;
            }

            return true;
        }

        friend bool operator!=(const Polynomial& lhs, const Polynomial& rhs) { return !(lhs == rhs); }

        Polynomial operator-();

        Polynomial& operator+=(const Polynomial&);
        friend Polynomial operator+(Polynomial lhs, const Polynomial& rhs)
        {
            lhs += rhs;
            return lhs;
        }

        Polynomial& operator-=(const Polynomial&);
        friend Polynomial operator-(Polynomial lhs, const Polynomial& rhs)
        {
            lhs -= rhs;
            return lhs;
        }

        Polynomial& operator*=(const Polynomial&);
        friend Polynomial operator*(Polynomial lhs, const Polynomial& rhs)
        {
            lhs *= rhs;
            return lhs;
        }

        // division of a polynomials doesn't always result in a polynomial so the '/' and '/='
        // operators are left out instead the divide function which returns
        // two polynomials, the quotient and the remainder, is implemented
        friend std::tuple <Polynomial, Polynomial> divide(const Polynomial& dividend, const Polynomial& divisor);

    protected:

    private:
        std::vector<double> coefficients;
        int degree;

        void simplify();
};

#endif // POLYNOMIAL_H
