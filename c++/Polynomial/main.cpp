//#include "UnitTest++.h"
#include "Polynomial.h"

int main()
{
    std::vector<double> coefficients1{1, 2, 3};
    Polynomial a = Polynomial(coefficients1);

    std::vector<double> coefficients2{5, 8, -5};
    Polynomial b = Polynomial(coefficients2);

    std::vector<double> coefficients3{1, 3, 5, 7};
    Polynomial c = Polynomial(coefficients3);

    Polynomial d = a + b;
    Polynomial e = a - c;
    Polynomial f = b * c;

    Polynomial g;
    Polynomial h;

    std::tie(g, h) = divide(f, a);

    Polynomial i = g * a + h;

    a.print();
    b.print();
    c.print();
    d.print();
    e.print();
    f.print();
    g.print();
    h.print();
    i.print();

    //return UnitTest::RunAllTests();
}

