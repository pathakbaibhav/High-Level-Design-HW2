// -*- C++ -*- vim600:syntax=cpp:sw=2:tw=78:fmr=<<<,>>>
#include "Testbench.h"
#include <systemc>

using namespace std;
using namespace sc_core;

sc_trace_file* trace_file;  // Global trace file pointer

void Testbench::end_of_elaboration(void) 
{ 
  //< callback
  cout << "End of elaboration" << endl;

  // Create a VCD trace file in the specified directory
  trace_file = sc_create_vcd_trace_file("results/ClkDivCounter");

  // Trace the clock and count signals
  sc_trace(trace_file, myClk, "myClk");
  sc_trace(trace_file, myClkDiv, "myClkDiv");

  cout << "Tracing signals to results/ClkDivCounter.vcd file" << endl;
}

void Testbench::Testbench_thread(void) 
{ //< Process
  cout << "Simulation Started!" << endl;

  while (true) 
  {
    wait(myClkDiv.default_event()); // Wait for clock signal change

    std::cout << "Divided Clock signal changed: " << myClkDiv.read() << std::endl;
  }

}

Testbench::~Testbench() 
{ //< Destructor
  cout << "Destroy " << name() << endl;

  // Close the VCD trace file
  sc_close_vcd_trace_file(trace_file);
}
