typedef int s32;

extern "C" s32 func_00364D78(s32 arg0, s32 arg1);

struct Obj00459CC8 {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_00459CC8(char *arg0, s32 arg1) {
    s32 t1 = *(s32 *)(arg0 + arg1 * 0x10 + 0x1C);
    s32 t0 = ((struct Obj00459CC8 *)arg0)->unk4;
    return func_00364D78(t0, t1);
}
