#ifndef Testbench_h
#define Testbench_h
// -*- C++ -*- vim600:syntax=cpp:sw=2:tw=78:fmr=<<<,>>>
#include <systemc>
SC_MODULE(Testbench)
{

  // Constructor 
  SC_CTOR(Testbench)
  {
    std::cout << "Constructing "
        << name() << std::endl;
    SC_THREAD(Testbench_thread);
  }//endconstructor


  void end_of_elaboration(void); //< Processes
  void Testbench_thread(void); //< Processes
  virtual ~Testbench(); //< Destructor
};
#endif