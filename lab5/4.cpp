#include <iostream>
#include <cmath>

int func_a(int n);
int func_b(int n);

int main(){
    for(int i=1; i<=15;i=i+1){
        std::cout <<"a_"<<i<<" = "<<func_a(i) << std::endl;
        std::cout <<"b_"<<i<<" = "<<func_b(i) << std::endl;
    }
}

int func_a(int n){
    int o;
    if (n==1) {
        return 1;
    }else{
        return 3*func_b(n-1) + 2*func_a(n-1);
    }
}

int func_b(int n){
    if (n==1) {
        return 1;
    }else{
        return 2*func_a(n-1) + func_b(n-1);
    }
}