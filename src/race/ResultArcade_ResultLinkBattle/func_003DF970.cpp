typedef int s32;

struct S { char pad[0x60]; s32 unk60; };

extern "C" void func_003DF970(S *arg0, s32 arg1) {
    arg0->unk60 = arg1;
}
