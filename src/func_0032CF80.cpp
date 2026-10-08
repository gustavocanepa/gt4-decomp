typedef int s32;

typedef void (*FnPtr)(s32, s32, s32);

struct Struct_0032CF80 {
    char pad0[0xC];
    FnPtr unkC;
};

extern "C" void func_0032CF80(struct Struct_0032CF80 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unkC(arg1, arg2, arg3);
}
