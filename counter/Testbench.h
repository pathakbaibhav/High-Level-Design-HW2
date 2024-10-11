#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>
#include "ClkGen.h"
#include "Counter.h"

SC_MODULE(Testbench) 
{
public:
    sc_signal<bool> myClk;
    ClkGen myClkGen;

    sc_signal<int> count;
    Counter counter;

    //Constructor
    SC_CTOR(Testbench) : myClk("myClk"), myClkGen("myClkGen"), count("count"), counter("counter")
    {
        std::cout << "Constructing " << name() << std::endl;

        // Connection to Clock generator
        myClkGen.clk_out(myClk);

        // Connection to Clock Counter
        counter.clk(myClk);
        counter.count(count);

      SC_THREAD(Testbench_thread);
    }

    // Process
    void end_of_elaboration(void);
    void Testbench_thread(void);

    // Destructor 
    virtual ~Testbench();
};

#endif // TESTBENCH_H
