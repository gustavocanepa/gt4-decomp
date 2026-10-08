typedef int s32;

typedef void (*FnPtr)(s32 arg0, s32 arg1, s32 arg2);

struct Struct_0032E4B8 {
    char pad0[0xC];
    FnPtr unkC;
};

extern "C" void func_0032E4B8(struct Struct_0032E4B8 *arg0, s32 arg1) {
    arg0->unkC(arg1, 0, 0);
}
