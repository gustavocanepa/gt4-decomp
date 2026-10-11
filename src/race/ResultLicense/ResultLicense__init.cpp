#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 ResultArcade__init();                            /* extern */
s32 get_license_mode_by_database_for_gt4_prologue(s32);                             /* extern */
s32 ResultLicense__disableEffect(void *);                      /* extern */
s32 GranTurismo4__GetTimeString(s32, void *, s32);    /* extern */

struct ResultLicense__virtual_01_arg1 {
    char pad0[0x70];
    s32 unk70;
};
struct ResultLicense__virtual_01_arg0 {
    char pad0[0x544];
    s8 unk544;
    char pad545[0x23];
    f32 unk568;
    s32 unk56C;
    s32 unk570;
    s32 unk574;
};

void ResultLicense__init(char *arg0, char *arg1) {
    s32 temp_v0;

    ResultArcade__init();
    temp_v0 = get_license_mode_by_database_for_gt4_prologue(((struct ResultLicense__virtual_01_arg1 *)arg1)->unk70);
    ((struct ResultLicense__virtual_01_arg0 *)arg0)->unk570 = 0;
    ((struct ResultLicense__virtual_01_arg0 *)arg0)->unk56C = temp_v0;
    ((struct ResultLicense__virtual_01_arg0 *)arg0)->unk574 = 0;
    GranTurismo4__GetTimeString(0x157529FF, arg0 + 0x6C, 0x20);
    ((struct ResultLicense__virtual_01_arg0 *)arg0)->unk544 = 0;
    ((struct ResultLicense__virtual_01_arg0 *)arg0)->unk568 = 0x1.0000000000000p+0f;
    ResultLicense__disableEffect(arg0);
}

}
