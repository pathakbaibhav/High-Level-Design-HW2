#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>
#include "ClkGen.h"
#include "Counter.h"
#include "ClkDiv.h"
#include "Monitor.h"

SC_MODULE(Testbench) 
{
public:
    sc_signal<bool> myClk;
    ClkGen myClkGen;

    sc_fifo<int> myCountCh;
    Counter counter;

    sc_signal<bool> myClkDiv;
    ClkDiv myClkDivMod;

    Monitor monitor;

    //Constructor
    SC_CTOR(Testbench) : myClk("myClk"), myClkGen("myClkGen"), myCountCh("10"), counter("counter"), myClkDiv("myClkDiv"), myClkDivMod("myClkDivMod"), monitor("monitor")
    {
        std::cout << "Constructing " << name() << std::endl;

        // Connection to Clock generator
        myClkGen.clk_out(myClk);

        // Connection to Clock Counter
        counter.clk(myClkDiv);
        counter.count_out(myCountCh);

        myClkDivMod.clk(myClk);
        myClkDivMod.clk_div(myClkDiv);

        // Connect Monitor to the FIFO
        monitor.myCountCh(myCountCh);

      SC_THREAD(Testbench_thread);
    }

    // Process
    void end_of_elaboration(void);
    void Testbench_thread(void);

    // Destructor 
    virtual ~Testbench();
};

#endif // TESTBENCH_H
