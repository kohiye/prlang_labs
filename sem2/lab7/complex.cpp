#include <iostream>
#include <cassert>
#include <cmath>

class Complex{
private:
    double m_Re{};
    double m_Im{};
public:
    Complex() = default;
    Complex(double real, double img=0):m_Re{real},m_Im{img}{};

    Complex& operator= (const Complex& num);

    friend Complex operator+(const Complex& num1, const Complex& num2);
    friend Complex operator-(const Complex& num1, const Complex& num2);
    friend Complex operator*(const Complex& num1, const Complex& num2);
    friend Complex operator/(const Complex& num1, const Complex& num2);
    friend std::ostream& operator<<(std::ostream& out, const Complex& num);
    friend std::istream& operator>>(std::istream& in, Complex& num);
    friend bool operator== (const Complex& num1, const Complex& num2);
    friend bool operator!= (const Complex& num1, const Complex& num2);
    friend bool operator< (const Complex& num1, const Complex& num2);
    friend bool operator> (const Complex& num1, const Complex& num2);
    friend bool operator<= (const Complex& num1, const Complex& num2);
    friend bool operator>= (const Complex& num1, const Complex& num2);

    Complex operator-() const;
    Complex operator+() const;
    bool operator!() const;

    double absValue() const {
        return std::sqrt(m_Re*m_Re + m_Im*m_Im);
    };
};

Complex& Complex::operator= (const Complex& num){
    m_Re = num.m_Re;
    m_Im = num.m_Im;
    return *this;
};


bool operator== (const Complex& num1, const Complex& num2)
{
    return (num1.m_Re == num2.m_Re && num1.m_Im == num2.m_Im);
};
bool operator!= (const Complex& num1, const Complex& num2)
{
    return !(operator==(num1,num2));
};
bool operator< (const Complex& num1, const Complex& num2)
{
    return num1.absValue() < num2.absValue();
};
bool operator> (const Complex& num1, const Complex& num2)
{
    return operator<(num2, num1);
};
bool operator<= (const Complex& num1, const Complex& num2)
{
    return !(operator>(num1, num2));
};
bool operator>= (const Complex& num1, const Complex& num2)
{
    return !(operator<(num1, num2));
};

Complex operator+(const Complex& num1, const Complex& num2){
    return {num1.m_Re + num2.m_Re, num1.m_Im+num2.m_Im};
};
Complex operator-(const Complex& num1, const Complex& num2){
    return {num1.m_Re - num2.m_Re, num1.m_Im - num2.m_Im};
};
Complex operator*(const Complex& num1, const Complex& num2){
    return Complex(num1.m_Re*num2.m_Re-num1.m_Im*num2.m_Im, num1.m_Re*num2.m_Im-num2.m_Re*num1.m_Im);
};
Complex operator/(const Complex& num1, const Complex& num2){
    double re {(num1.m_Re*num2.m_Re + num1.m_Im*num2.m_Im)/static_cast<double>(num2.m_Re*num2.m_Re + num2.m_Im*num2.m_Im)};
    double im {(num1.m_Im*num2.m_Re - num1.m_Re*num2.m_Im)/static_cast<double>(num2.m_Re*num2.m_Re + num2.m_Im*num2.m_Im)};
    return Complex(re, im);
};
std::ostream& operator<<(std::ostream& out, const Complex& num){
    out << num.m_Re << ((num.m_Im>=0)?" + ":" - ") << ((num.m_Im>=0)?num.m_Im:num.m_Im * (-1)) << " * i";
    return out;
};
std::istream& operator>>(std::istream& in, Complex& num){
    in >> num.m_Re;
    in >> num.m_Im;
    return in;
};

Complex Complex::operator-() const {
    return {-m_Re,-m_Im};
}; 
Complex Complex::operator+() const {
    return {m_Re,m_Im};
};
bool Complex::operator!() const {
    return {m_Re == 0.0 && m_Im == 0.0};
};


int main(){
    Complex cnum1{3, 3};
    std::cout << cnum1 << '\n';
    Complex num{8};
    std::cout << num + cnum1 << '\n';
    assert((num+cnum1 == Complex{11,3}));
    cnum1 = num;
    std::cout << cnum1 << '\n';
    assert((cnum1 == 8));
    cnum1 = cnum1 + Complex{0, -8};
    std::cout << cnum1 << '\n';
    assert((cnum1 == Complex{8,-8}));
    assert((cnum1 > num));
    cnum1 = cnum1 / num;
    assert((cnum1 == Complex{1,-1}));
    assert((cnum1 < num));
    return 0;
}
