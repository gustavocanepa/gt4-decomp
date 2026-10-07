typedef int s32;

struct S { char pad[0x10]; s32 unk10; };

extern "C" void func_0021A7A0(S *arg0, s32 arg1) {
    arg0->unk10 = arg1;
}
