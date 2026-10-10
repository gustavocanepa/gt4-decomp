#include "types.h"
#include "gt4/ParticleManager.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005C1628(void *);                      /* extern */

extern char ParticleManager__vtable[];
void ParticleManager__structor_1(struct ParticleManager *arg0, s32 arg1) {
    arg0->unk3AC = (s32)ParticleManager__vtable;
    func_005C1628(arg0->unk0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
