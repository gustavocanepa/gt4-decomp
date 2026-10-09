typedef int s32;

struct S { char pad[0x14]; s32 unk14; };

extern "C" void func_002CDA40(S *arg0, s32 arg1) {
    arg0->unk14 = arg1;
}
