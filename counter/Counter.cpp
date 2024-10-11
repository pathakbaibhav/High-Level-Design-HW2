#include "Counter.h"

void Counter::increment() 
{
    if(clk.read() == true)
    {
        if(count_out.num_free() > 0)
        {
            count++;
            count_out.write(count);
        }

    }
}
