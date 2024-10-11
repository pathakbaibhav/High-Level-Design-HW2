#ifndef CLKDIV_H
#define CLKDIV_H

#include <systemc.h>

SC_MODULE(ClkDiv) {
    sc_in<bool> clk;        // Clock input
    sc_out<bool> clk_div;   // Divided clock output

    int edge_count;         // Counter for clock edges

    void divide_clock();    // Method to divide the clock

    SC_CTOR(ClkDiv) : edge_count(0) {
        SC_METHOD(divide_clock);
        sensitive << clk.pos() << clk.neg();  // Trigger on both rising and falling edges
    }
};

#endif // CLKDIV_H
