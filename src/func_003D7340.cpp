typedef int s32;
typedef signed char s8;

struct Obj {
    char pad[4];
    s32 unk4;
};

extern "C" s32 func_00344CE8(s32 arg0, s8 arg1);

extern "C" s32 func_003D7340(Obj *arg0, s32 arg1) {
    char *p = (char *)arg0 + arg1;
    return func_00344CE8(arg0->unk4, *(s8 *)(p + 0xC));
}
