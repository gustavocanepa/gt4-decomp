typedef int s32;

struct S { char pad[0x34]; s32 unk34; };

extern "C" void func_003E75E0(S *arg0, s32 arg1) {
    arg0->unk34 = arg1;
}
