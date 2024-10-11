#include "ClkDiv.h"

void ClkDiv::divide_clock() {
    edge_count++;  // Increment edge count on each clock edge

    if (edge_count == 4) {
        clk_div.write(!clk_div.read());  // Flip the state of the divided clock signal
        edge_count = 0;  // Reset edge count
    }
}
