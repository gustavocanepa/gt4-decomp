#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char RaceEntryInformation__vtable[];
struct RaceEntryInformation {
    char unk_0[0x178];
    s32 unk178;
    void * unk17C;
};
s32 func_005C1628(struct RaceEntryInformation *); /* extern */

void RaceEntryInformation__structor_1(struct RaceEntryInformation *arg0, s32 arg1) {
    arg0->unk17C = (void *)(s32)RaceEntryInformation__vtable;
    func_00444210((s32) arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
