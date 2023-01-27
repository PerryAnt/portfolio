#include "Polynomial.h"

void Polynomial::print()
{
    for (auto i: coefficients)
    {
        std::cout << i << ' ';
    }

    std::cout << std::endl;
}

//Construct zero polynomial
Polynomial::Polynomial()
{
    degree = 0;
    coefficients.push_back(0);
}

//Construct polynomial with coefficients from a vector
Polynomial::Polynomial(std::vector<double> coeff)
{
    coefficients = std::move(coeff);
    if(coefficients.size() > 0)
        degree = coefficients.size() - 1;
    simplify();
}

int Polynomial::get_degree() const
{
    return degree;
}

int Polynomial::get_leading_coefficient() const
{
    return coefficients.back();
}

bool Polynomial::is_zero()
{
    return degree == 0 && coefficients[0] == 0;
}

double Polynomial::operator()(double x)
{
    double res = coefficients[degree];
    for(int i = degree - 1 ; i >= 0; i--)
    {
        res *= x;
        res += coefficients[i];
    }

    return res;
}

Polynomial Polynomial::operator- ()
{
    Polynomial res = Polynomial(coefficients);

    for(int i = 0; i <= res.degree; i++)
    {
        res.coefficients[i] *= -1;
    }

    return res;
}

Polynomial& Polynomial::operator+= (Polynomial const &rhs) {
    if(rhs.degree > this->degree)
    {
        this->degree = rhs.degree;
        this->coefficients.resize(rhs.degree + 1);
    }

    for(int i = 0; i <= rhs.degree; i++)
    {
        coefficients[i] += rhs.coefficients[i];
    }

    this->simplify();
    return *this;
}

//can probably rewrite this in terms of += and negation operators
Polynomial& Polynomial::operator-= (Polynomial const &rhs) {

    if(rhs.degree > this->degree)
    {
        this->degree = rhs.degree;
        this->coefficients.resize(rhs.degree + 1);
    }

    for(int i = 0; i <= rhs.degree; i++)
    {
        coefficients[i] -= rhs.coefficients[i];
    }

    this->simplify();
    return *this;
}

Polynomial& Polynomial::operator*= (Polynomial const &rhs) {
    //keep track of degree of lhs
    int old_degree = this->degree;

    // degree of product is the sum of the degrees of the factors
    // set new degree
    this->degree = this->degree + rhs.degree;
    this->coefficients.resize(this->degree + 1);

    // c(x) = p(x) * q(x)
    // c_i = sum( p_j * q_(i-j) )

    for(int i = this->degree; i >=0; i--)
    {


        this->coefficients[i] *= rhs.coefficients[0];

        for(int j = 0; j < i; j++)
        {
            // there's probably a clever way to make this loop have the correct limits
            // but this works


            if(j <= old_degree && i-j <= rhs.degree)
            {
                this->coefficients[i] += this->coefficients[j] * rhs.coefficients[i-j];
            }
        }
    }
    //since the leading coefficient can't be zero, simplify isn't needed
    return *this;
}

std::tuple <Polynomial, Polynomial> divide(const Polynomial& dividend, const Polynomial& divisor)
{
    int deg = dividend.degree - divisor.degree;

    if(deg < 0)
    {
        return std::make_tuple(Polynomial(), dividend);
    }

    std::vector<double> coeff;
    coeff.resize(deg + 1);
    std::fill(coeff.begin(), coeff.end(), 0);
    coeff[deg] = 1;

    Polynomial quotient = Polynomial(coeff);
    Polynomial term = quotient;
    double x = 1;
    Polynomial remainder = dividend;

    for(;deg >= 0;deg--)
    {
        x = remainder.coefficients[deg+divisor.degree]/divisor.get_leading_coefficient();

        quotient.coefficients[deg] = x;
        term.coefficients[deg] = x;

        remainder -= term * divisor;

        term.coefficients.pop_back();
        term.degree--;
    }

    return std::make_tuple(quotient,remainder);

}


// zeroes at the end of the coefficient vector are removed so a polynomial has a unique representation
// 1 + 2*x and 1 + 2*x + 0*x^2 are both the same polynomial, but the first representation makes more sense
void Polynomial::simplify(){
    for(int i = degree; i > 0; i--)
    {
        if(coefficients[i] == 0)
        {
            coefficients.pop_back();
        }
        else
        {
            break;
        }
    }

    degree = coefficients.size() - 1;
    return;
}
