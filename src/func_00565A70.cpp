typedef int s32;

struct S { char pad[0x14]; s32 unk14; };

extern "C" void func_00565A70(S *arg0) {
    arg0->unk14 = 0;
}
