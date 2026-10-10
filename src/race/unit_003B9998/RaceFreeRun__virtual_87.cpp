#include "types.h"
#include "gt4/RaceFreeRun.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0038B7C0(void *, s32);             /* extern */
s32 func_0038B8D8(void *, s32);             /* extern */
s32 func_0038B990(void *, s32);             /* extern */
s32 func_0038BA90(void *, s32);             /* extern */
s32 func_0038BAB0(void *, s32);             /* extern */
s32 func_003BA938(void *, s32);             /* extern */
s32 RaceLicense__virtual_87();                            /* extern */
s32 func_00460560();                            /* extern */

void RaceFreeRun__virtual_87(void *arg0) {
    RaceLicense__virtual_87();
    ((struct RaceFreeRun *)arg0)->unk24698 = 0;
    ((struct RaceFreeRun *)arg0)->unk246A4 = 0;
    ((struct RaceFreeRun *)arg0)->unk246A0 = 0;
    func_003BA938(arg0, 0);
    func_00460560();
    func_0038B7C0(arg0, 0);
    func_0038B8D8(arg0, 0);
    func_0038BAB0(arg0, 0);
    func_0038B990(arg0, 0);
    func_0038BA90(arg0, 0);
}
