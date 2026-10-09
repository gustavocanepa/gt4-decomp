typedef int s32;
typedef signed char s8;

struct Obj {
    s32 unk0;
    char pad[0x1A - 4];
    s8 unk1A;
};

extern "C" s32 func_00615320(struct Obj *arg0, s32 arg1) {
    s32 cond = (arg1 == 0);
    s32 old = arg0->unk0;
    arg0->unk0 = arg1;
    arg0->unk1A = (s8)(cond << 2);
    return old;
}
