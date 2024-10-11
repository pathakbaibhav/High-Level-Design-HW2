#include "Counter.h"

void Counter::increment() 
{
    if(clk.read() == true)
    {
        count++;
        count_out.write(count);  // Increment the count

    }
}
