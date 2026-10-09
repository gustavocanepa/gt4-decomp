typedef int s32;

struct S { char pad[0x80]; s32 unk80; };

extern "C" void func_004515A8(S *arg0) {
    arg0->unk80 = 0;
}
