#include "Counter.h"

void Counter::increment() 
{
    count.write(count + 1);  // Increment the count
}
