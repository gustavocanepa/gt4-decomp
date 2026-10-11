#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);


void func_004452F8(void *, void *);              /* extern */

struct RaceFreeRunInformation__virtual_12_temp_s0 {
    char pad0[0x166];
    s8 unk166;
    char pad167[0x11];
    s32 unk178;
};
struct RaceFreeRunInformation__virtual_12_temp_s3 {
    char pad0[0x178];
    s32 unk178;
};

struct RaceFreeRunInformation__virtual_12_arg1 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x342C];
    s32 unk3444;
    s32 unk3448;
};

void RaceSolitaireInformation__updateEntryCar(s32 arg0, void *arg1) {
    s32 temp_s1;
    struct RaceFreeRunInformation__virtual_12_temp_s0 *temp_s0;
    struct RaceFreeRunInformation__virtual_12_temp_s3 *temp_s3;

    temp_s3 = (void *)(arg0 + 0x130);
    temp_s0 = (s8 *)arg1 + 0x20;
    temp_s1 = ((struct RaceFreeRunInformation__virtual_12_arg1 *)arg1)->unk14;
    func_004452F8(temp_s0, temp_s3);
    temp_s0->unk178 = (s32) ((temp_s1 != 0) ? 1 : 0x100);
    if (temp_s0->unk166 != 0) {
        ((struct RaceFreeRunInformation__virtual_12_arg1 *)arg1)->unk3448 = (s32) temp_s3->unk178;
    }
    ((struct RaceFreeRunInformation__virtual_12_arg1 *)arg1)->unk3444 = 0;
}
