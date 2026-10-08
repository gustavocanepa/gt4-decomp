typedef int s32;

typedef void (*FnPtr)(s32 arg0);

struct Obj005C9B30 {
    char pad0[0x4];
    FnPtr unk4;
};

extern "C" void func_005C9B30(struct Obj005C9B30 *arg0, s32 arg1, s32 arg2) {
    arg0->unk4(arg2);
}
