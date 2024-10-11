// -*- C++ -*- vim600:syntax=cpp:sw=2:tw=78:fmr=<<<,>>>
#include "Testbench.h"
#include <systemc>
using namespace std;
using namespace sc_core;

void Testbench::end_of_elaboration(void) { //< callback
  cout << "End of elaboration" << endl;
}

void Testbench::Testbench_thread(void) { //< Process
  cout << "Testbench World!" << endl;
}

Testbench::~Testbench() { //< Destructor
  cout << "Destroy " << name() << endl;
}