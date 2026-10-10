#include "types.h"
#include "gt4/SparkParticle.h"
void *func_005A4724(void *, const void *, unsigned int);

void SparkParticle__Init(struct SparkParticle *arg0) {
    arg0->unk8_u16 = (u16) (arg0->unk8_u16 & 0xFFFE);
}
