#include "types.h"

extern "C" void mBox__deepCopy(void *arg0, void *arg1);
extern "C" void *__dynamic_cast_2(s32, s32, s32, void *, s32, void *);

extern char mSliderBar__tf[];
extern char hObject__tf[];

extern "C" void mSliderBar__virtual_08(void *arg0, void *arg1) {
    char *var_a3;
    char *temp_v0;
    char *src;
    char *dst;

    mBox__deepCopy(arg0, arg1);
    var_a3 = 0;
    if (arg1 != 0) {
        temp_v0 = *(char **)((char *)arg1 + 4);
        var_a3 = (char *)__dynamic_cast_2(*(s32 *)(temp_v0 + 4), (s32)mSliderBar__tf, 0,
                                       (char *)arg1 + *(s16 *)temp_v0, (s32)hObject__tf, arg1);
    }
    if (var_a3 != 0) {
        src = var_a3 + 0xCC;
        dst = (char *)arg0 + 0xCC;
        *(s32 *)((char *)arg0 + 0x104) = *(s32 *)(var_a3 + 0x104);
        *(s32 *)(dst + 0x0) = *(s32 *)(src + 0x0);
        *(s32 *)(dst + 0x4) = *(s32 *)(src + 0x4);
        *(s32 *)(dst + 0x8) = *(s32 *)(src + 0x8);
        *(s32 *)(dst + 0xC) = *(s32 *)(src + 0xC);
        *(s32 *)(dst + 0x10) = *(s32 *)(src + 0x10);
        *(s32 *)((char *)arg0 + 0xC0) = *(s32 *)(var_a3 + 0xC0);
        *(s32 *)((char *)arg0 + 0xE0) = *(s32 *)(var_a3 + 0xE0);
        *(s32 *)((char *)arg0 + 0xE4) = *(s32 *)(var_a3 + 0xE4);
        *(s32 *)((char *)arg0 + 0xE8) = *(s32 *)(var_a3 + 0xE8);
    }
}
