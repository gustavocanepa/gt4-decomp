typedef int s32;
typedef short s16;
typedef float f32;

struct Obj {
    char pad0[0x84];
    f32 unk84;
    char pad1[0xA1A - 0x88];
    s16 unkA1A;
};

extern "C" void func_003A9418(struct Obj *arg0, f32 fparg0) {
    arg0->unk84 = fparg0;
    arg0->unkA1A = (s16)(s32)(fparg0 + 0.5f);
}
