#include "ClkGen.h"
#include <iostream>

void ClkGen::cycle() 
{
    for (uint32_t i =0; i < 100; i++) 
    {
        clk_out = !clk_out;
        std::cout << "Pre CLK: " << clk_out << std::endl;

        wait(2, SC_NS);

        std::cout << "Post CLK: " << clk_out << std::endl << std::endl;
    }
}