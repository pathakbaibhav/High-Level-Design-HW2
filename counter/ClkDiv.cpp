#include "ClkDiv.h"

void ClkDiv::divide_clock() {
    while (true) {
    wait(clk.default_event()); // Wait for the clock signal
    count++;
    std::cout << "count: " << count << std::endl;

    // Toggle clkDiv every 4 counts
    if (count % 4 == 0) {
        clk_div = !clk_div; // Toggle clkDiv
        std::cout << "clkDiv toggled to: " << clk_div << std::endl;
    }
}

}