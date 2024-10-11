#include "Counter.h"

void Counter::increment() 
{
    if(clk == 1)
    {
        count.write(count + 1);  // Increment the count

    }
}
