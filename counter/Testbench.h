#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>
#include "ClkGen.h"

SC_MODULE(Testbench) 
{
public:
    sc_signal<bool> myClk;
    ClkGen myClkGen;

    //Constructor
    SC_CTOR(Testbench) : myClk("myClk"), myClkGen("myClkGen") 
    {
        std::cout << "Constructing " << name() << std::endl;

        // Connection to Clock generator
        myClkGen.clk_out(myClk);

      SC_THREAD(Testbench_thread);
    }

    void end_of_elaboration(void);
    void Testbench_thread(void);
    virtual ~Testbench();
};

#endif // TESTBENCH_H
