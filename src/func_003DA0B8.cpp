typedef int s32;

struct S { char pad[0x78]; s32 unk78; };

extern "C" void func_003DA0B8(S *arg0, s32 arg1) {
    arg0->unk78 = arg1;
}
