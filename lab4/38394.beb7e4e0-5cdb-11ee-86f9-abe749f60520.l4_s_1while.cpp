#include <iostream>


int
main ()
{
    int i=1;
    bool a,b;
    while(i<=500){
        a = i%5==0;
        b = i%7==0;
        if(a&&b){
            std::cout << "fuzzbuzz" << std::endl;
        }else if(a){
            std::cout << "fuzz" << std::endl;
        }else if(b){
            std::cout << "buzz" << std::endl;
        }else{
            std::cout << i << std::endl;
        }
        i++;
    }
  return 0;
}
