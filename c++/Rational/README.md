This is a simple class for creating and manipulating rational numbers.

Rationals, also called frations, are numbers of the form a/b, where a and b are both integers. The first number is called the numerator and the second number is called the denominator.

### Constructors

Two constructors are provided. The default constructor creates initializes the value to zero.

```cpp
#include "Rational.h"

Rational r = Rational();
```

The second constructor takes two integers: the numerator and the denominator, in that order

```cpp
int a = 1;
int b = 2;
Rational r = Rational(a, b);
```

### Simplification

Rational numbers are considered reduced if the numerator and denominator do not have any common factors.

For example, 1/2 and 2/4 represent the same number but 1/2 is reduced and 2/4 is not.

Non-private functions will only return reduced fractions.


### Negation

The unary - operator can be used to obtain the negative of a rational number.

-x = (-a)/b

```cpp
Rational r1 = Rational();
Rational r2 = Rational();

r2 = -r1
```

Non-private functions will only return fractions with a positive denominator.

Negative fractions are represented by having a negative numerator.

### Getting Numerator and Denominator

The numerator and denominator can be obtained by using the get_numerator() and get_denominator() functions, respectively.

```cpp
Rational r1 = Rational();

int a = r1.get_numerator();
int b = r1.get_denominator();
```

### Zero and Infinity

Zero is represented by a numerator of 0 and a denominator of 1.

Positive infinity is representing by a numerator of 1 and a denominator of 0.

Negative infinity is representing by a numerator of -1 and a denominator of 0.


### Addition, Substraction, Multiplication, an Division

Addition, substraction, multiplication, and division can be performed using the +, -, *, and / operators.

If 

x = a/b

y = c/d

then

x + y = (ad + bc)/(bd)

x - y = (ad - bc)/(bd)


x * y = ac/(bd)

x / y = (ad)/(bc)


```cpp
Rational r1 = Rational();
Rational r2 = Rational();
Rational r3 = Rational();
Rational r4 = Rational();
Rational r5 = Rational();
Rational r6 = Rational();

r3 = r1 + r2;
r4 = r1 - r2;
r5 = r1 * r2;
r6 = r1 / r2;
```

The +=, -=, *= , and /= operators can also be used.

```cpp
Rational r1 = Rational();
Rational r2 = Rational();

r1 += r2;
r1 -= r2;
r1 *= r2;
r1 /= r2;
```

### Comparisons

The is_zero() function returns true if the fraction is the zero and false otherwise

```cpp
Rational r1 = Rational();

if(f1.is_zero()){
  // ...
}
```

The == and != operators check if two fractions are equal or not equal, respectively.
Two rationals are equal if they have the same numerators and the same denominators.

```cpp
Rational r1 = Rational();
Rational r2 = Rational();

if(r1 == r2){
  // ...
}

if(r1 != r2){
  // ...
}
```

A rational x = a/b is greater than (>) a number y = c/d if ad - bc > 0. 

The other comparisons (>=, <, and <=) follow from the definitions of = and >.

### Reciprocal

The reciprocal() function returns the reciprocal of a number which is obtained by swapping the numerator and denominator and swapping their signs if necessary.

1/x = b/a

```cpp
Rational r1 = Rational(a, b);
Rational r2 = r1.reciprocal();
```
