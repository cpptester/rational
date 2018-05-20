#include "rational.hpp"
#include <windows.h>
#include <iostream>

static void printRational(const syrup::Rational<int>& r)
{
    std::cout << r.numerator() << "/" << r.denominator() << std::endl;
}

static void printRationalMul(const syrup::Rational<int>& r1, const syrup::Rational<int>& r2)
{
    std::cout << r1.numerator() << "/" << r1.denominator() << 
        " * " << r2.numerator() << "/" << r2.denominator() << " = ";
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    syrup::Rational<int> a(1, 3);
    syrup::Rational<int> b(2, 5);
    syrup::Rational<int> c = a * b;

    c =  a * b ;
    printRationalMul(a, b);
    printRational(c);

    //約分
    syrup::Rational<int> d(10000, 560000);
    d.reduce();
    printRational(d);

    return 0;
}
