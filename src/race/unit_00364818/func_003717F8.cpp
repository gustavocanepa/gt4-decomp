typedef int s32;

struct S { char pad[0x78]; s32 unk78; };

extern "C" void func_003717F8(S *arg0) {
    arg0->unk78 = 0;
}
