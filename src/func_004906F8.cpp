typedef int s32;

struct S { char pad[0x4C]; s32 unk4C; };

extern "C" void func_004906F8(S *arg0, s32 arg1) {
    arg0->unk4C = arg1;
}
