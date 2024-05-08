#include <iostream>
#include <cmath>
#include <iomanip>


int
main ()
{
  double y;
  std::cout << "---------------" << "\n   x  |  y   " << 
  "\n---------------"<< std::endl;
  for(double x=-2;x<=2;x+=0.5){
    y = -2.4*std::pow(x,2)+5*x-3;
    std::cout <<std::setw(4)<< x << "  |" <<std::setw(6)<< y <<" "<< std::endl;
  }
  std::cout << "---------------" << std::endl;
  return 0;
}
