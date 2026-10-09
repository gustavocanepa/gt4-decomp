typedef int s32;

struct S { char pad[0x54]; s32 unk54; };

extern "C" void func_0025C2D8(S *arg0, s32 arg1) {
    arg0->unk54 = arg1;
}
