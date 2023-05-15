#include "command.h"
#include "sched.h"
#include "irq.h"


void
led_TOGGLE(void)
{

}
DECL_TASK(led_TOGGLE);


int main() {
    extern void SystemInit();
    SystemInit();

    sched_main();

    return 0;
}


extern uint32_t _ebss, _heap_end;
// Return the start of memory available for dynamic allocations
void *
dynmem_start(void)
{
    return &_ebss;
}

// Return the end of memory available for dynamic allocations
void *
dynmem_end(void)
{
    return &_heap_end;
}