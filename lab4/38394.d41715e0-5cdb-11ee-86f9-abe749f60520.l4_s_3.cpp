#include <iostream>


int
main ()
{
  int n;
  long long f=1;
  std::cout << "Finding factorial." << std::endl;
  std::cout << "Input a number factorial of which you want to find"
  << std::endl;
  std::cin >> n;
  for(int i=1;i<=n;i++){
    f=f*i;
  }
  std::cout << n << "! = "<< f << std::endl;
  return 0;
}
