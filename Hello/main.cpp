#include "Hello.h"
#include <iostream>
using namespace std;
using namespace sc_core;
int sc_main(int argc, char *argv[]) 
{
  Hello top_i("top_i");
  cout << "Starting" << endl;
  sc_start();
  cout << "Exiting" << endl;
  return 0;
}//end main
