#include <iostream>


int main (){
    int n;
    double s=1;
    std::cout << "Calculating series 1+1/2+1/3+...+1/n" << std::endl;
    std::cout << "Give n: ";
    std::cin >> n;
    for(int i=2;i<=n;i++){
        s = s + 1.0/i;
    }
    std::cout << "Sum of the first " << n <<" elements = "<<s<< std::endl;
    return 0;
}
