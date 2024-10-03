// -*- C++ -*- vim600:syntax=cpp:sw=2:tw=78:fmr=<<<,>>>
#include "Hello.h"
#include <systemc>
using namespace std;
using namespace sc_core;

void Hello::end_of_elaboration(void) { //< callback
  cout << "End of elaboration" << endl;
}

void Hello::Hello_thread(void) { //< Process
  cout << "Hello World!" << endl;
}

Hello::~Hello() { //< Destructor
  cout << "Destroy " << name() << endl;
}
