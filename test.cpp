#include "rational.hpp"
#include <windows.h>
#include <iostream>

static void printRational(const syrup::Rational<int>& r)
{
    std::cout << r.numerator() << "/" << r.denominator() << std::endl;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    syrup::Rational<int> a(1, 3);
    syrup::Rational<int> b(2, 5);
    syrup::Rational<int> c = a * b;

    c = a / b;
    printRational(c);

    c = a * 3;
    printRational(c);
    
    c = 3 * a;
    printRational(c);

    c = a / 3;
    c.reduce();
    printRational(c);    

    c = 3 / a;
    printRational(c);

    return 0;
}
