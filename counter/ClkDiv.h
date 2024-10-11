#ifndef CLKDIV_H
#define CLKDIV_H

#include <systemc.h>

SC_MODULE(ClkDiv) {
    sc_in<bool> clk;        // Clock input
    sc_out<bool> clk_div;   // Divided clock output

    int count;         // Counter for clock edges

    void divide_clock();    // Method to divide the clock

    SC_CTOR(ClkDiv) 
    {
        count = 0;
        SC_THREAD(divide_clock);
    }
};

#endif // CLKDIV_H