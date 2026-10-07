typedef int s32;

struct S { char pad[0x7C]; s32 unk7C; };

extern "C" void func_00371A50(S *arg0) {
    arg0->unk7C = 0;
}
