#include <iostream>


int
main ()
{
  bool a, b;
  for (int i = 1; i <= 500; i++)
    {
      a = i % 5 == 0;
      b = i % 7 == 0;
      if (a && b){
	    std::cout << "fuzzbuzz" << std::endl;
	  }else if(a){
	    std::cout << "fuzz" << std::endl;
	  }else if (b){
	    std::cout << "buzz" << std::endl;
	  }else{
	    std::cout << i << std::endl;
	  }

    };

  return 0;
}
