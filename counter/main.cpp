#include "Testbench.h"
#include <iostream>
using namespace std;
using namespace sc_core;
int sc_main(int argc, char *argv[]) 
{
  Testbench top_i("top_i");
  cout << "Starting" << endl;
  sc_start();
  cout << "Exiting" << endl;
  return 0;
}//end main
