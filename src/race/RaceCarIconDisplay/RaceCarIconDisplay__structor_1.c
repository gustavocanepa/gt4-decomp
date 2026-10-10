#include "types.h"
#include "gt4/RaceCarIconDisplay.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003A9608(void *);                      /* extern */
s32 func_003A9758(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char RaceCarIconDisplay__vtable[];
void RaceCarIconDisplay__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0();
    ((struct RaceCarIconDisplay *)arg0)->unk18 = 0;
    ((struct RaceCarIconDisplay *)arg0)->unk1C = 0;
    ((struct RaceCarIconDisplay *)arg0)->unk14 = (s32)RaceCarIconDisplay__vtable;
    ((struct RaceCarIconDisplay *)arg0)->unk20 = 0;
    ((struct RaceCarIconDisplay *)arg0)->unk24 = 0;
    func_003A9758(arg0 + 0x28);
    func_003A9608(arg0 + 0x44);
}
