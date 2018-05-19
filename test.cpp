#include "rational.hpp"
#include <windows.h>
#include <iostream>

static void printRational(const Rational<int>& r)
{
    std::cout << r.numerator() << "/" << r.denominator() << std::endl;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Rational<int> a(1, 3);
    Rational<int> b(2, 5);
    Rational<int> c = a * b;

    c = a / b;
    printRational(c);

    c = a * 3;
    printRational(c);
    
    c = 3 * a;
    printRational(c);

    c = a / 3;
    printRational(c);

    c = 3 / a;
    printRational(c);    

    return 0;
}
