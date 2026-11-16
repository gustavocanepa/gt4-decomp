typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;

extern "C" void mBox__deepCopy(void *arg0, void *arg1);
extern "C" void *__dynamic_cast_2(s32, s32, s32, void *, s32, void *);

extern char mOptionMenu__tf[];
extern char hObject__tf[];

extern "C" void mOptionMenu__virtual_08(void *arg0, void *arg1) {
    void *var_v0;
    char *temp_v0;

    mBox__deepCopy(arg0, arg1);
    var_v0 = 0;
    if (arg1 != 0) {
        temp_v0 = *(char **)((char *)arg1 + 4);
        var_v0 = __dynamic_cast_2(*(s32 *)(temp_v0 + 4), (s32)mOptionMenu__tf, 0,
                               (char *)arg1 + *(s16 *)temp_v0, (s32)hObject__tf, arg1);
    }
    if (var_v0 != 0) {
        char *src = (char *)var_v0 + 0xD8;
        char *dst = (char *)arg0 + 0xD8;
        *(s32 *)(dst + 0x0) = *(s32 *)(src + 0x0);
        *(s32 *)(dst + 0x4) = *(s32 *)(src + 0x4);
        *(s32 *)(dst + 0x8) = *(s32 *)(src + 0x8);
        *(s32 *)(dst + 0xC) = *(s32 *)(src + 0xC);
        *(s32 *)(dst + 0x10) = *(s32 *)(src + 0x10);
    }
}
