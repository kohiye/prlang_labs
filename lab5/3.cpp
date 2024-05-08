#include <iostream>
#include <cmath>

int fctrl(int n);

int main(){
    for(int a=1; a<=19; a+=3){
        std::cout << "a = " << a << " ; " << (3+a)/std::pow((a-4), 2)
        << std::endl;
    }
}