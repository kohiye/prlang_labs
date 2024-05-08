#include <numeric>
#include <cassert>

class Rational
{
private:
    int m_num{};
    int m_denom{1};
public:
    Rational(int num, int denom=1):m_num{num},m_denom{denom}{simplify();};
    
    void simplify()
    {
        int gcd{std::gcd(m_num, m_denom)};
        if (gcd){
            m_num /= gcd;
            m_denom /= gcd;
        }
    };

    Rational operator+() const;
    Rational operator-() const;
    friend Rational operator+(const Rational& q1, const Rational& q2);
    friend Rational operator-(const Rational& q1, const Rational& q2);
    friend Rational operator*(const Rational& q1, const Rational& q2);
    friend Rational operator/(const Rational& q1, const Rational& q2);

    Rational& operator+=(const Rational& q);
    Rational& operator-=(const Rational& q);
    Rational& operator*=(const Rational& q);
    Rational& operator/=(const Rational& q);

    friend bool operator==(const Rational& q1, const Rational& q2);
    friend bool operator!=(const Rational& q1, const Rational& q2);

    int getNumerator() const {return m_num;};
    int getDenominator() const {return m_denom;};
};

Rational Rational::operator+() const {
    return {m_num, m_denom};
};
Rational Rational::operator-() const {
    return {-m_num, m_denom};
};

Rational operator+(const Rational& q1, const Rational& q2){
    int denom{q1.m_denom * q2.m_denom};
    int num{q1.m_num * q2.m_denom + q2.m_num * q1.m_denom};
    Rational res{num, denom};
    res.simplify();
    return res;
};

Rational operator-(const Rational& q1, const Rational& q2){
    return operator+(q1, -q2);
};

Rational operator*(const Rational& q1, const Rational& q2){
    Rational res{q1.m_num * q2.m_num, q1.m_denom * q2.m_denom};
    res.simplify();
    return res;
};

Rational operator/(const Rational& q1, const Rational& q2){
    Rational res{q1.m_num * q2.m_denom, q1.m_denom * q2.m_num};
    res.simplify();
    return res;
};

Rational& Rational::operator+=(const Rational& q){
    *this = {*this + q};
    return *this;
};
Rational& Rational::operator-=(const Rational& q){
    *this = {*this - q};
    return *this;
};
Rational& Rational::operator*=(const Rational& q){
    *this = {*this * q};
    return *this;
};
Rational& Rational::operator/=(const Rational& q){
    *this = {*this / q};
    return *this;
};

bool operator==(const Rational& q1, const Rational& q2){
    return (q1.m_num == q2.m_num && q1.m_denom == q2.m_denom);
};
bool operator!=(const Rational& q1, const Rational& q2){
    return !(operator==(q1, q2));
};

int main(){
    Rational q1{8};
    Rational q2{3, 4};
    assert((+q1 == 8) && "uplus");
    assert((-q1 == -8) && "uminus");
    assert((+q2 == Rational{3, 4}) && "uplus");
    assert((-q2 == Rational{-3, 4}) && "uminus");
    assert((q1 + q2 == Rational{35, 4}) && "add");
    assert((q1 - q2 == Rational{29, 4}) && "subt");
    assert((q1 * q2 == Rational{6}) && "mult");
    assert((q1 / q2 == Rational{32, 3}) && "div");
    assert((q1 + 8 == 16) && "add int");
    assert((q1 - 10 == -2) && "subt int");
    assert((q1 * 8 == 64) && "mult int");
    assert((q1 / 2 == 4) && "div int");
    q1 += q2;
    assert((q1 == Rational{35, 4}) && "add-assign");
    q1 -= q2;
    assert((q1 == 8) && "sub-assign");
    q2*=q1;
    assert((q2 == 6) && "mult-assign");
    q1/=q2;
    assert((q1 == Rational{8, 6}) && "div-assign");

    return 0;
}
