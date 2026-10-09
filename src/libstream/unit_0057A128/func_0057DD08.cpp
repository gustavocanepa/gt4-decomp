typedef int s32;
typedef signed char s8;

struct Obj0057DD08 {
    char pad0[4];
    s8 *unk4;
};

extern "C" s32 func_0057DD08(struct Obj0057DD08 *arg0, s8 arg1) {
    s8 **bp;
    s8 *temp_v1;

    bp = &arg0->unk4;
    temp_v1 = *bp;
    *temp_v1 = arg1;
    temp_v1 = temp_v1 + 1;
    *bp = temp_v1;
    return 0;
}
