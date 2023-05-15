#include "compiler.h" // barrier
#include "stdint.h"

static inline void irq_disable(void) {

}

static inline void irq_enable(void) {

}

typedef uint8_t irqstatus_t;

static inline irqstatus_t irq_save(void) {

}

static inline void irq_restore(irqstatus_t flag) {

}

static inline void irq_wait(void) {
}

static inline void irq_poll(void) {
}