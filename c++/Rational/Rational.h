#ifndef RATIONAL_H
#define RATIONAL_H

#pragma once

#include <iostream>
#include <numeric>

class Rational
{
    public:
        Rational();
        Rational(int, int);

        void print();

        bool is_zero();

        int get_numerator() const;

        int get_denominator() const;

        friend std::ostream& operator<<(std::ostream& out, Rational const& r)
        {
            out << r.numerator << "/" << r.denominator;
            out << std::endl;
            return out;
        }

        friend bool operator==(const Rational& lhs, const Rational& rhs)
        {
            if(lhs.numerator != rhs.numerator)
                return false;

            if(lhs.denominator != rhs.denominator)
                return false;

            return true;
        }

        friend bool operator!=(const Rational& lhs, const Rational& rhs) { return !(lhs == rhs); }

        Rational operator-();
        Rational reciprocal();

        Rational& operator+=(const Rational&);
        friend Rational operator+(Rational lhs, const Rational& rhs)
        {
            lhs += rhs;
            return lhs;
        }

        Rational& operator-=(const Rational&);
        friend Rational operator-(Rational lhs, const Rational& rhs)
        {
            lhs -= rhs;
            return lhs;
        }

        Rational& operator*=(const Rational&);
        friend Rational operator*(Rational lhs, const Rational& rhs)
        {
            lhs *= rhs;
            return lhs;
        }

        Rational& operator/=(const Rational&);
        friend Rational operator/(Rational lhs, const Rational& rhs)
        {
            lhs /= rhs;
            return lhs;
        }

    protected:

    private:
        int numerator;
        int denominator;

        void simplify();
};

#endif // RATIONAL_H
