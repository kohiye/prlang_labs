#include <iostream>

int main()
{
    int n, o;
    std::cin >> n;
    while(n>0){
        o = n % 10;
        n = (n-o)/10;
        std::cout << o;
    }

    return 0;
}