typedef int s32;

struct S { char pad[0x1B4]; s32 unk1B4; };

extern "C" void func_00379CB8(S *arg0, s32 arg1) {
    arg0->unk1B4 = arg1;
}
