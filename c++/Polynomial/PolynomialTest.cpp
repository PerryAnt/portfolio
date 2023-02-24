#include "UnitTest++.h"
#include "Polynomial.h"

namespace
{
    TEST(GetDegree)
    {
        std::vector<double> coefficients1{1, 2, 3};
        Polynomial poly1 = Polynomial(coefficients1);

        std::vector<double> coefficients2{1, 2, 3, 4};
        Polynomial poly2 = Polynomial(coefficients2);

        CHECK_EQUAL(poly1.get_degree(), 2);
        CHECK_EQUAL(poly2.get_degree(), 3);
    }

    TEST(GetLeadingCoefficient)
    {
        std::vector<double> coefficients1{1, 2, 5};
        Polynomial poly1 = Polynomial(coefficients1);

        std::vector<double> coefficients2{1, 2, 3, 17};
        Polynomial poly2 = Polynomial(coefficients2);

        CHECK_EQUAL(poly1.get_leading_coefficient(), 5);
        CHECK_EQUAL(poly2.get_leading_coefficient(), 17);
    }

    TEST(IsZero)
    {
        Polynomial poly1 = Polynomial();
        std::vector<double> coefficients2{1, 2, 3, 17};
        Polynomial poly2 = Polynomial(coefficients2);

        CHECK(poly1.is_zero());
        CHECK(!poly2.is_zero());
    }

    TEST(FunctionCall)
    {
        std::vector<double> coefficients1{1};
        Polynomial poly1 = Polynomial(coefficients1);

        std::vector<double> coefficients2{3, 2, 1};
        Polynomial poly2 = Polynomial(coefficients2);

        CHECK_EQUAL(poly1(0), 1);
        CHECK_EQUAL(poly2(0), 3);

        CHECK_EQUAL(poly1(1), 1);
        CHECK_EQUAL(poly2(1), 6);

        CHECK_EQUAL(poly1(2), 1);
        CHECK_EQUAL(poly2(2), 11);

        CHECK_EQUAL(poly1(-1), 1);
        CHECK_EQUAL(poly2(-1), 2);
    }

    TEST(Equals)
    {
        std::vector<double> coefficients{1, 2, 3};
        Polynomial poly1 = Polynomial(coefficients);
        Polynomial poly2 = Polynomial(coefficients);
        Polynomial poly3 = Polynomial(poly1);
        Polynomial poly4 = Polynomial();
        poly4 = poly1;

        //self equals
        CHECK(poly1 == poly1);
        //identical equals
        CHECK(poly1 == poly2);
        //reverse order
        CHECK(poly2 == poly1);
        //copy constructor
        CHECK(poly1 == poly3);
        //assignment operator
        CHECK(poly1 == poly4);
    }


    TEST(NotEqual)
    {
        std::vector<double> coefficients1{1, 2, 3};
        Polynomial poly1 = Polynomial(coefficients1);

        std::vector<double> coefficients2{1, 2, 4};
        Polynomial poly2 = Polynomial(coefficients2);

        std::vector<double> coefficients3{1, 2, 3, 4};
        Polynomial poly3 = Polynomial(coefficients3);

        CHECK(poly1 != poly2);
        CHECK(poly1 != poly3);
    }

    TEST(Negation)
    {
        std::vector<double> coefficients1{1, 2, 3};
        Polynomial poly1 = Polynomial(coefficients1);

        std::vector<double> coefficients2{-1, -2, -3};
        Polynomial poly2 = Polynomial(coefficients2);

        CHECK(-poly1 ==  poly2);
        CHECK( poly1 == -poly2);

        //double degation
        Polynomial poly3 = -poly1;
        CHECK(poly1 == -poly3);
    }

    TEST(AdditionWithoutSimplify)
    {
        std::vector<double> coefficients1{1, 2, 3};
        Polynomial poly1 = Polynomial(coefficients1);

        std::vector<double> coefficients2{5, 8, -5};
        Polynomial poly2 = Polynomial(coefficients2);

        std::vector<double> coefficients3{6, 10, -2};
        Polynomial poly3 = Polynomial(coefficients3);

        CHECK(poly3 == poly1 + poly2);
        CHECK(poly3 == poly1 - (-poly2));

        poly2 += poly1;

        CHECK(poly3 == poly2);


        std::vector<double> coefficients4{5, 8, -5, 10};
        Polynomial poly4 = Polynomial(coefficients4);

        std::vector<double> coefficients5{6, 10, -2, 10};
        Polynomial poly5 = Polynomial(coefficients5);

        CHECK(poly5 == poly1 + poly4);

        poly4 += poly1;

        CHECK(poly5 == poly4);
    }

    TEST(AdditionWithSimplify)
    {
        std::vector<double> coefficients1{1, 2, 3};
        Polynomial poly1 = Polynomial(coefficients1);

        std::vector<double> coefficients2{5, 8, -3};
        Polynomial poly2 = Polynomial(coefficients2);

        std::vector<double> coefficients3{6, 10};
        Polynomial poly3 = Polynomial(coefficients3);

        CHECK(poly3 == poly1 + poly2);
        CHECK(poly3 == poly1 - (-poly2));

        poly2 += poly1;

        CHECK(poly3 == poly2);
    }


    TEST(SubtractionWithoutSimplify)
    {
        std::vector<double> coefficients1{1, 2, 3};
        Polynomial poly1 = Polynomial(coefficients1);

        std::vector<double> coefficients2{5, 8, -5};
        Polynomial poly2 = Polynomial(coefficients2);

        std::vector<double> coefficients3{4, 6, -8};
        Polynomial poly3 = Polynomial(coefficients3);

        CHECK(poly3 == poly2 - poly1);
        CHECK(poly3 == poly2 + (-poly1));

        poly2 -= poly1;

        CHECK(poly3 == poly2);


        std::vector<double> coefficients4{5, 8, -5, 10};
        Polynomial poly4 = Polynomial(coefficients4);

        std::vector<double> coefficients5{4, 6, -8, 10};
        Polynomial poly5 = Polynomial(coefficients5);

        CHECK(poly5 == poly4 - poly1);

        poly4 -= poly1;

        CHECK(poly5 == poly4);
    }

    TEST(SubtractionWithSimplify)
    {
        std::vector<double> coefficients1{1, 2, 3};
        Polynomial poly1 = Polynomial(coefficients1);

        std::vector<double> coefficients2{5, 8, 3};
        Polynomial poly2 = Polynomial(coefficients2);

        std::vector<double> coefficients3{4, 6};
        Polynomial poly3 = Polynomial(coefficients3);

        CHECK(poly3 == poly2 - poly1);
        CHECK(poly3 == poly2 + (-poly1));

        poly2 -= poly1;

        CHECK(poly3 == poly2);

        std::vector<double> coefficients4{5, 8, -5, 10, 12};
        Polynomial poly4 = Polynomial(coefficients4);

        std::vector<double> coefficients5{4, 8, -8, 10, 12};
        Polynomial poly5 = Polynomial(coefficients5);

        std::vector<double> coefficients6{-1, 0, -3};
        Polynomial poly6 = Polynomial(coefficients6);

        CHECK(poly6 == poly5 - poly4);

        poly5 -= poly4;
        CHECK(poly6 == poly5);

        poly4 -= poly4;
        CHECK(poly4.is_zero());

        poly5 = poly5 - poly5;
        CHECK(poly5.is_zero());
    }

    TEST(Multiplication)
    {
        std::vector<double> coefficients1{1, 2, 3};
        Polynomial poly1 = Polynomial(coefficients1);

        std::vector<double> coefficients2{5, 8, -5};
        Polynomial poly2 = Polynomial(coefficients2);

        std::vector<double> coefficients3{5, 18, 26, 14, -15};
        Polynomial poly3 = Polynomial(coefficients3);

        CHECK(poly3 == poly2 * poly1);

        poly2 *= poly1;

        CHECK(poly3 == poly2);

        std::vector<double> coefficients4{5, 8, -5, 10};
        Polynomial poly4 = Polynomial(coefficients4);

        std::vector<double> coefficients5{5, 18, 26, 24, 5, 30};
        Polynomial poly5 = Polynomial(coefficients5);

        CHECK(poly5 == poly4 * poly1);

        poly4 *= poly1;

        CHECK(poly5 == poly4);

        Polynomial poly6 = Polynomial();
        Polynomial poly7 = poly5 * poly6;
        CHECK(poly7.is_zero());

    }

    TEST(DivisionWithoutRemainder)
    {
        std::vector<double> coefficients1{5, 18, 26, 14, -15};
        Polynomial poly1 = Polynomial(coefficients1);

        std::vector<double> coefficients2{1, 2, 3};
        Polynomial poly2 = Polynomial(coefficients2);

        std::vector<double> coefficients3{5, 8, -5};
        Polynomial poly3 = Polynomial(coefficients3);

        Polynomial poly4 = Polynomial();

        Polynomial poly5;
        Polynomial poly6;

        std::tie(poly5, poly6) = divide(poly1, poly2);
        CHECK(poly5 == poly3);
        CHECK(poly6 == poly4);
    }

    TEST(DivisionWithRemainder)
    {
        std::vector<double> coefficients1{5, 18, 26, 14, -15};
        Polynomial poly1 = Polynomial(coefficients1);

        std::vector<double> coefficients2{1, 1, 1};
        Polynomial poly2 = Polynomial(coefficients2);

        std::vector<double> coefficients3{12, 29, -15};
        Polynomial poly3 = Polynomial(coefficients3);

        std::vector<double> coefficients4{-7, -23};
        Polynomial poly4 = Polynomial(coefficients4);

        Polynomial poly5;
        Polynomial poly6;

        std::tie(poly5, poly6) = divide(poly1, poly2);
        CHECK(poly5 == poly3);
        CHECK(poly6 == poly4);
    }

    TEST(DivisionWithZeroQuotient)
    {
        std::vector<double> coefficients1{1, 1};
        Polynomial poly1 = Polynomial(coefficients1);

        std::vector<double> coefficients2{1, 1, 1};
        Polynomial poly2 = Polynomial(coefficients2);

        Polynomial poly3 = Polynomial();

        std::vector<double> coefficients4{1, 1};
        Polynomial poly4 = Polynomial(coefficients4);

        Polynomial poly5;
        Polynomial poly6;

        std::tie(poly5, poly6) = divide(poly1, poly2);
        CHECK(poly5 == poly3);
        CHECK(poly6 == poly4);
    }

    TEST(SimplifyInConstructor)
    {
        std::vector<double> coefficients1{1, 2, 0};
        Polynomial poly1 = Polynomial(coefficients1);

        std::vector<double> coefficients2{1, 2};
        Polynomial poly2 = Polynomial(coefficients2);

        CHECK(poly1 == poly2);


        std::vector<double> coefficients3{5, 8, 0, 0, 0, 0};
        Polynomial poly3 = Polynomial(coefficients3);

        std::vector<double> coefficients4{5, 8, 0};
        Polynomial poly4 = Polynomial(coefficients4);

        std::vector<double> coefficients5{5, 8};
        Polynomial poly5 = Polynomial(coefficients5);

        CHECK(poly3 == poly4);
        CHECK(poly4 == poly5);
        CHECK(poly5 == poly3);

        std::vector<double> coefficients6{0, 0, 0, 0};
        Polynomial poly6 = Polynomial(coefficients6);
        CHECK(poly6.is_zero());
    }
}
