This is a simple class for creating and manipulating polynomial.

Polynomials are functions of the form f(x) = a_0 + a_1 * x ^ 1 + a_2 * x ^2 + ...

The highest power of x with a non-zero coefficient is called the degree of the polynomial.
The leading coefficient is the coefficient corresponding to that power of x.

### Constructors

Two constructors are provided. The default constructor creates the zero polynomial, f(x) = 0.

```cpp
#include "Polynomial.h"

Polynomial p = Polynomial();
```

The second constructor takes a vector and creates a polynomial with a degree of (vector.size() - 1) and the coefficients of the polynomial are given by the elements of the vector.

```cpp
std::vector<double> coefficients{1, 2, 3};
Polynomial p = Polynomial(coefficients);
```

### Trailing Zeroes and Simplification

Polynomials are considered simplified if the coefficient of the highest degree term in the polynomial is non-zero, unless the polynomial is the zero polynomial.

Consider the following two polynomials:

f(x) = 1 + 2 * x
g(x) = 1 + 2 * x + 0 * x ^ 2

These are same polynomial but the first one is simplified and the second one is not. 

Only simplified polynomials are considered valid and non-private functions returning a polynomial will only return simplified polynomials.

### Evaluating Polynomials

A polynomial can be evaluated at a given x value using the () operator

```cpp
std::vector<double> coefficients{1, 2, 3};
Polynomial p = Polynomial(coefficients);
double y = p(5);
```

### Getting Degree and Leading Coefficient

The degree and leading coefficient of a polynomial can be obtained by using the get_degree() and get_leading_coefficient() functions, respectively.

```cpp
Polynomial p = Polynomial();

int d = p.get_degree();
int c = p.get_leading_coefficient() ;
```

### Addition, Substraction, and Multiplication

Addition, substraction, and multiplication can be performed using the +, -, and * operators.

Addition and substraction of polynomials is done elementwise:

f(x) = a_0 + a_1 * x ^ 1 + a_2 * x ^ 2 + ...

g(x) = b_0 + b_1 * x ^ 1 + b_2 * x ^ 2 + ...

f(x) + g(x) = (a_0 + b_0) + (a_1 + b_1) * x ^ 1 + (a_2 + b_2) * x ^ 2 + ...

f(x) - g(x) = (a_0 - b_0) + (a_1 - b_1) * x ^ 1 + (a_2 - b_2) * x ^ 2 + ...

Multiplication is done by application of the distributive property of multiplication over addition.

```cpp
Polynomial p1 = Polynomial();
Polynomial p2 = Polynomial();
Polynomial p3 = Polynomial();
Polynomial p4 = Polynomial();
Polynomial p5 = Polynomial();

p3 = p1 + p2;
p4 = p1 - p2;
p5 = p1 * p2;
```

The +=, -=, and *= operators can also be used.

```cpp
Polynomial p1 = Polynomial();
Polynomial p2 = Polynomial();

p1 += p2;
p1 -= p2;
p1 *= p2;
```

### Division

Dividing a polynomial by another polynomial does not always result in a single polynomial (there is also a remainder) 
so the / and /= operators are not implemented.

Division can be instead be performed by using the divide() function.

divide(f(x), g(x)) returns a tuple of q(x) and r(x) such that

f(x) = g(x) * q(x) + r(x)

```cpp
Polynomial p1 = Polynomial();
Polynomial p2 = Polynomial();

Polynomial q;
Polynomial r;

std::tie(g, h) = divide(p1, p2);
```

### Negation

The unary - operator can be used to obtain the negative of a polynomial. Negation is done elementwise.

-f(x) = -a_0 - a_1 * x ^ 1 - a_2 * x ^ 2 - ...

Adding a polynomial to it's own negation results in the zero polynomial.

```cpp
Polynomial p1 = Polynomial();
Polynomial p2 = Polynomial();

p2 = -p1
```

### Comparisons

The is_zero() function returns true if the polynomial is the zero polynomial and false otherwise

```cpp
Polynomial p1 = Polynomial();

if(p1.is_zero()){
  // ...
}
```

The == and != operators check if two polynomials are equal or not equal, respectively.
Two polynomials are considered equal if they have the same degree and the same coefficients.

```cpp
Polynomial p1 = Polynomial();
Polynomial p2 = Polynomial();

if(p1 == p2){
  // ...
}

if(p1 != p2){
  // ...
}
```


Other types of comparisons (< , >, <= , >=) do not make sense for polynomials so they are not implemented.
