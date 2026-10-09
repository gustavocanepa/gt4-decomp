typedef int s32;

struct S { char pad[0x54]; s32 unk54; };

extern "C" void func_002C1840(S *arg0) {
    arg0->unk54 = arg0->unk54 ^ 1;
}
