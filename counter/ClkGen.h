#ifndef CLKGEN_H
#define CLKGEN_H

#include <systemc.h>

SC_MODULE(ClkGen) 
{
    sc_out<bool> clk_out; // Clock output

    void cycle();

    SC_CTOR(ClkGen) 
    {
        SC_THREAD(cycle); // Using SC_THREAD
        
        /*
        Answer to the question: Why use SC_THREAD instead of SC_METHOD? 
        (1): SC_THREAD can wait on events or delays (e.g., `wait()` statements), 
              allowing the process to pause and resume later when triggered by an event.
        (2): Since our use case involves a clock, we need the process to be triggered
              periodically at certain intervals. SC_THREAD supports the use of delays
              (e.g., `wait(N, SC_NS)`).
        (3): SC_THREAD preserves the state between activations, so we can maintain
              the state of the clock over time. In contrast, SC_METHOD does not retain
              state and just executes once when triggered and then terminates.
        */

    }
};

#endif // CLKGEN_H