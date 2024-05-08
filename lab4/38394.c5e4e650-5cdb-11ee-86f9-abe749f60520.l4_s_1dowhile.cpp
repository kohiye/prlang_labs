#include <iostream>


int
main (){
  int i = 1;
  bool a, b;
  do{
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
	  i++;
    }while (i<=500);
    return 0;
}
