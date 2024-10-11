#ifndef MONITOR_H
#define MONITOR_H

#include <systemc.h>
#include <iostream>

SC_MODULE(Monitor) {
  sc_fifo_in<int> myCountCh;  // FIFO input channel

  void monitor_thread() {
    int value;
    while (true) {
      value = myCountCh.read();  // Read from FIFO
      std::cout << "Monitor received value from FIFO: " << value << std::endl;
    }
  }

  SC_CTOR(Monitor) {
    SC_THREAD(monitor_thread);  // Register the monitor thread
  }
};

#endif
