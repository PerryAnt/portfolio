//#include "UnitTest++.h"
#include "Rational.h"

int main()
{
    Rational rat1 = Rational(1, 2);
    Rational rat2 = Rational(2, 3);
    Rational rat3 = Rational(57, 7);

    Rational rat4 = rat1 + rat2;
    rat4 += rat3;

    Rational rat5 = rat1 + rat2;
    rat5 *= rat3;

    Rational rat6 = rat5 - rat4;
    Rational rat7 = rat5/rat4;

    rat1.print();
    rat2.print();
    rat3.print();
    rat4.print();
    rat5.print();
    rat6.print();
    rat7.print();

    //return UnitTest::RunAllTests();
}
