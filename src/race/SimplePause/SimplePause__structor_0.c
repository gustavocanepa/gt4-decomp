#include "types.h"
#include "gt4/SimplePause.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 SimplePause__init(void *);                      /* extern */
s32 PauseBase__structor_0();                            /* extern */

extern char SimplePause__vtable[];
void SimplePause__structor_0(struct SimplePause *arg0) {
    PauseBase__structor_0();
    arg0->unk8 = (s32)SimplePause__vtable;
    SimplePause__init(arg0);
}
