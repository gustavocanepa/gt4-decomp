typedef int s32;

struct S { char pad[0x7C]; s32 unk7C; };

extern "C" void func_004513B8(S *arg0, s32 arg1) {
    arg0->unk7C = arg1;
}
