#pragma once

namespace syrup {

template <typename T>
T gcd(T a, T b)
{
    T c;
    while (a != 0) {
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}

template <typename T>
class Rational {
public:
    Rational(T numerator = 0, T denominator = 1)
        : m_iNumerator(numerator)
        , m_iDenominator(denominator){};
    Rational(const Rational<T>& r){};
    virtual ~Rational(){};

    T numerator() const { return m_iNumerator; }
    T denominator() const { return m_iDenominator; }

    explicit operator int() const { return m_iNumerator / m_iDenominator; }
    explicit operator double() const { return ((double)m_iNumerator) / m_iDenominator; }

    void reduce()
    {
        T a = gcd(m_iNumerator, m_iDenominator);
        if (a != -1) {
            m_iNumerator /= a;
            m_iDenominator /= a;
        }
    }

private:
    T m_iNumerator;
    T m_iDenominator;
};

template <typename T>
inline const Rational<T> operator*(const Rational<T>& lhs,
    const Rational<T>& rhs)
{
    return Rational<T>(lhs.numerator() * rhs.numerator(),
        lhs.denominator() * rhs.denominator());
}

template <typename T>
inline const Rational<T> operator*(const Rational<T>& lhs, const T rhs)
{
    return Rational<T>(lhs.numerator(), lhs.denominator() * rhs);
}

template <typename T>
inline const Rational<T> operator*(const T lhs, const Rational<T>& rhs)
{
    return Rational<T>(rhs.numerator(), rhs.denominator() * lhs);
}

template <typename T>
inline const Rational<T> operator/(const Rational<T>& lhs,
    const Rational<T>& rhs)
{
    return Rational<T>(lhs.numerator() * rhs.denominator(),
        lhs.denominator() * rhs.numerator());
}

template <typename T>
inline const Rational<T> operator/(const Rational<T>& lhs, const T& rhs)
{
    return Rational<T>(lhs.numerator() * rhs, lhs.denominator());
}

template <typename T>
inline const Rational<T> operator/(const T& lhs, const Rational<T>& rhs)
{
    return Rational<T>(lhs * rhs.denominator(), rhs.numerator());
}

template <typename T>
inline const Rational<T> operator-(const Rational<T>& lhs, const T& rhs) {}

} // namespace syrup