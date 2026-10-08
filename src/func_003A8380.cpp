typedef int s32;
typedef short s16;
typedef float f32;

struct Obj003A8380 {
    char pad0[0x7A];
    s16 unk7A;
};

extern "C" void func_003A8380(struct Obj003A8380 *arg0, f32 fparg0) {
    arg0->unk7A = (s32)(fparg0 + 0.5f);
}
