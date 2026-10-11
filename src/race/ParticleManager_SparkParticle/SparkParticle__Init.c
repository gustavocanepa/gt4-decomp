#include "types.h"
#include "gt4/SparkParticle.h"
void *memcpy(void *, const void *, unsigned int);

void SparkParticle__Init(struct SparkParticle *arg0) {
    arg0->unk8_u16 = (u16) (arg0->unk8_u16 & 0xFFFE);
}
