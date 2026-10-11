#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char RaceEventQueue__vtable[];
struct RaceEventQueue {
    char unk_0[0x828];
    void * unk828;
};
s32 func_005C1628(struct RaceEventQueue *);     /* extern */

void RaceEventQueue__structor_1(struct RaceEventQueue *arg0, s32 arg1) {
    arg0->unk828 = (void *)(s32)RaceEventQueue__vtable;
    func_005760A8(arg0, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
