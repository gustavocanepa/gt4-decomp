typedef int s32;
typedef signed char s8;

struct Obj2 {
    char pad[0x14];
    char *unk14;
};

extern "C" s32 func_00382C40(s32 arg0, s32 arg1, struct Obj2 *arg2) {
    char *p = arg2->unk14 + arg0;
    s8 b = *(s8 *)(p + 0x164);
    return b == 0;
}
