#include "types.h"
#include "gt4/Ipic.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char Ipic__vtable[];
s32 Ipic__structor_0(struct Ipic *arg0) {
    arg0->unk18 = (s32)Ipic__vtable;
}
