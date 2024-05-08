#include <iostream>
#include <cmath>

int fctrl(int n);

int main()
{
    double s, h=0.05, a=0.1, b=1, y;
    double eps = 0.0001;
    for(double x = a; x <= b; x = x + h){
        double el=1;
        int i=1;
        double o=1;
        while(el>=eps){
            el = std::pow((2*x),i)/fctrl(i);
            o = o + el;
            i=i+1;
        }
        std::cout << o << "  -  ";
        y = std::exp(2*x);
        std::cout << y <<std::endl;
    }
    return 0;
}

int fctrl(int n) {
    int f = 1;
    for(int i=1; i<=n; i=i+1){
        f=f*i;
    }
    return f;
}