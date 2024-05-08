#include <iostream>
#include <cmath>
#include <iomanip>


int
main ()
{
  int n,c;
  double e,s,m;
  std::cout << "Finding mean of a sequence." << std::endl;
  std::cout << "Enter the number of elements in the sequence: ";
  std::cin >> n;
  c=n;
  std::cout << "Enter each element of the sequence: " << std::endl;
  while(n>0){
    std::cout << "-> ";
    std::cin >> e;
    s += e;
    n = n-1;
  }
  std::cout << "Mean: " << s/c << std::endl;
  return 0;
}
