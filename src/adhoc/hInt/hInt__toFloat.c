#include "types.h"
#include "gt4/hInt.h"
void *memcpy(void *, const void *, unsigned int);

f32 hInt__toFloat(struct hInt *arg0) {
    return (f32) arg0->unk10;
}
