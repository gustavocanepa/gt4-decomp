typedef int s32;

struct S { char pad[0x2C]; s32 unk2C; };

extern "C" void func_002F3A30(S *arg0, s32 arg1) {
    arg0->unk2C = arg1;
}
