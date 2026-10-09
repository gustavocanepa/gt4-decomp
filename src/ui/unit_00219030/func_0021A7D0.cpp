typedef int s32;

struct S { char pad[0x1C]; s32 unk1C; };

extern "C" void func_0021A7D0(S *arg0, s32 arg1) {
    arg0->unk1C = arg1;
}
