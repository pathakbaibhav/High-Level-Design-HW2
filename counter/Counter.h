#ifndef COUNTER_H
#define COUNTER_H

#include <systemc.h>

SC_MODULE(Counter) 
{
    sc_in<bool> clk;          // Clock input
    sc_out<int> count;    // Count signal

    void increment(); // Method to increment the count

    SC_CTOR(Counter)
    {
        SC_METHOD(increment); // Sensitive to the rising edge of clk
        sensitive << clk;  // Trigger on rising edge of clk

        /*
        Answer to the question: Why use SC_METHOD instead of SC_THREAD?
        1. SC_METHOD is more efficient for event-driven processes like
            counting on a clock edge since it is sensitive to the clock
            and does not need explicit waiting.
        2. SC_METHOD is ideal for lightweight processes that do not require
            suspending or waiting, which is the case for this simple counter.
        3. SC_THREAD would be better suited for processes that need to use
            `wait()` statements and exhibit more complex behavior.
        */
    }

};

#endif // COUNTER_H
