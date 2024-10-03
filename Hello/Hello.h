#ifndef Hello_h
#define Hello_h
// -*- C++ -*- vim600:syntax=cpp:sw=2:tw=78:fmr=<<<,>>>
#include <systemc>
SC_MODULE(Hello)
{

  // Constructor 
  SC_CTOR(Hello)
  {
    std::cout << "Constructing "
        << name() << std::endl;
    SC_THREAD(Hello_thread);
  }//endconstructor


  void end_of_elaboration(void); //< Processes
  void Hello_thread(void); //< Processes
  virtual ~Hello(); //< Destructor
};
#endif
