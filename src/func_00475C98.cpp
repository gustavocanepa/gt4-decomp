typedef int s32;

struct S { char pad[0x28]; s32 unk28; };

extern "C" void func_00475C98(S *arg0, s32 arg1) {
    arg0->unk28 = arg1;
}
