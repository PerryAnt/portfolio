#include "UnitTest++.h"
#include "Rational.h"

namespace
{

    TEST(IsZero) {
        Rational rat1 = Rational();
        Rational rat2 = Rational(1, 2);

        CHECK(rat1.is_zero());
        CHECK(!rat2.is_zero());
    }

    TEST(Equals) {
        Rational rat1 = Rational(1, 2);
        Rational rat2 = Rational(1, 2);
        Rational rat3 = Rational(rat1);
        Rational rat4 = Rational();
        rat4 = rat1;

        //self equals
        CHECK(rat1 == rat1);
        //identical equals
        CHECK(rat1 == rat2);
        //reverse order
        CHECK(rat2 == rat1);
        //copy constructor
        CHECK(rat1 == rat3);
        //assignment operator
        CHECK(rat1 == rat4);
    }


    TEST(NotEqual) {
        Rational rat1 = Rational(1, 3);
        Rational rat2 = Rational(2, 3);
        Rational rat3 = Rational(1, 4);

        CHECK(rat1 != rat2);
        CHECK(rat1 != rat3);
    }

    TEST(Comparisons) {
        Rational rat1 = Rational(1, 3);
        Rational rat2 = Rational(2, 3);
        Rational rat3 = Rational(1, 4);

        CHECK(rat1 < rat2);
        CHECK(rat2 > rat1);
        CHECK(rat1 >= rat3);
        CHECK(rat3 <= rat2);

        CHECK(rat1 >= rat1);
    }

    TEST(Negation) {
        Rational rat1 = Rational( 1, 2);
        Rational rat2 = Rational(-1, 2);

        CHECK(-rat1 ==  rat2);
        CHECK( rat1 == -rat2);

        //negation is its own inverse
        Rational rat3 = -rat1;
        CHECK(rat1 == -rat3);
    }

    TEST(Reciprocal) {
        Rational rat1 = Rational(1, 2);
        Rational rat2 = Rational(2, 1);

        CHECK(rat1 ==  rat2.reciprocal());

        //reciprocal is its own inverse
        Rational rat3 = rat1.reciprocal();
        CHECK(rat1 == rat3.reciprocal());
    }

    TEST(AdditionWithoutSimplify) {
        Rational rat1 = Rational(1, 5);
        Rational rat2 = Rational(2, 5);
        Rational rat3 = Rational(3, 5);

        CHECK(rat3 == rat1 + rat2);
        CHECK(rat3 == rat1 - (-rat2));

        rat2 += rat1;
        CHECK(rat3 == rat2);


        Rational rat4 = Rational(1, 2);
        Rational rat5 = Rational(7, 10);

        CHECK(rat5 == rat1 + rat4);

        rat4 += rat1;
        CHECK(rat5 == rat4);
    }

    TEST(AdditionWithSimplify) {
        Rational rat1 = Rational(3, 12);
        Rational rat2 = Rational(5, 12);
        Rational rat3 = Rational(2, 3);

        CHECK(rat3 == rat1 + rat2);
        CHECK(rat3 == rat1 - (-rat2));

        rat2 += rat1;
        CHECK(rat3 == rat2);


        rat3 += -rat3;
        CHECK(rat3.is_zero());
    }


    TEST(SubtractionWithoutSimplify) {
        Rational rat1 = Rational(1, 3);
        Rational rat2 = Rational(2, 3);
        Rational rat3 = Rational(1, 3);
        CHECK(rat3 == rat2 - rat1);
        CHECK(rat3 == rat2 + (-rat1));

        rat2 -= rat1;
        CHECK(rat3 == rat2);

        Rational rat4 = Rational(1, 2);
        Rational rat5 = Rational(1, 6);
        CHECK(rat5 == rat4 - rat1);

        rat4 -= rat1;
        CHECK(rat5 == rat4);
    }

    TEST(SubtractionWithSimplify) {

        Rational rat1 = Rational(3, 12);
        Rational rat2 = Rational(5, 12);
        Rational rat3 = Rational(1, 6);
        CHECK(rat3 == rat2 - rat1);
        CHECK(rat3 == rat2 + (-rat1));

        rat2 -= rat1;
        CHECK(rat3 == rat2);

        rat2 -= rat2;
        CHECK(rat2.is_zero());

        rat3 = rat3 - rat3;
        CHECK(rat3.is_zero());
    }

    TEST(MultiplicationWithoutSimplify) {
        Rational rat1 = Rational(2, 3);
        Rational rat2 = Rational(5, 7);
        Rational rat3 = Rational(10, 21);
        CHECK(rat3 == rat2 * rat1);

        rat2 *= rat1;
        CHECK(rat3 == rat2);
    }

    TEST(MultiplicationWithSimplify) {
        Rational rat1 = Rational(2, 3);
        Rational rat2 = Rational(5, 2);
        Rational rat3 = Rational(5, 3);
        CHECK(rat3 == rat2 * rat1);

        rat2 *= rat1;
        CHECK(rat3 == rat2);

        Rational rat4 = Rational(3, 2);
        Rational rat5 = Rational(1, 1);
        CHECK(rat5 == rat4 * rat1);

        rat4 *= rat1;
        CHECK(rat5 == rat4);

        Rational rat6 = Rational();
        Rational rat7 = rat5 * rat6;
        CHECK(rat7.is_zero());
    }

    TEST(DivisionWithoutSimplify) {
        Rational rat1 = Rational(1, 2);
        Rational rat2 = Rational(3, 5);
        Rational rat3 = Rational(6, 5);
        CHECK(rat3 == rat2/rat1);
        CHECK(rat3 == rat2 * rat1.reciprocal());

        rat2 /= rat1;
        CHECK(rat3 == rat2);
    }

    TEST(DivisionWithSimplify) {
        Rational rat1 = Rational(2, 1);
        Rational rat2 = Rational(4, 3);
        Rational rat3 = Rational(2, 3);
        CHECK(rat3 == rat2/rat1);
        CHECK(rat3 == rat2 * rat1.reciprocal());

        rat2 /= rat1;
        CHECK(rat3 == rat2);
    }

    TEST(SimplifyInConstructor) {
        Rational rat1 = Rational(50, 100);
        Rational rat2 = Rational(1, 2);
        CHECK(rat1 == rat2);

        Rational rat3 = Rational(3, 5);
        Rational rat4 = Rational(6, 10);
        Rational rat5 = Rational(9, 15);
        Rational rat6 = Rational(21, 35);

        CHECK(rat3 == rat4);
        CHECK(rat3 == rat5);
        CHECK(rat3 == rat6);

        Rational rat7 = Rational(0, 100);
        CHECK(rat7.is_zero());
    }
}
