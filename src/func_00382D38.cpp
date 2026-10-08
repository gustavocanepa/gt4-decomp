typedef int s32;

struct S { char pad[0x184]; s32 unk184; };

extern "C" void func_00382D38(S *arg0, s32 arg1) {
    arg0->unk184 = arg1;
}
