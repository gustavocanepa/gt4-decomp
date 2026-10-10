#include "gt4/RaceSolitaireEntry.h"
extern "C" void func_0033B840(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceSolitaireEntry__vtable;

extern "C" void RaceSolitaireEntry__structor_1(struct RaceSolitaireEntry *arg0, int arg1) {
    arg0->unk20 = &RaceSolitaireEntry__vtable;
    func_0033B840(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
