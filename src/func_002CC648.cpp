typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
};

extern char D_0066FDD8;

extern "C" void func_002CC648(S *arg0, s32 arg1) {
    register s32 v1 asm("$3") = (s32)&D_0066FDD8;
    arg0->unk4 = arg1;
    arg0->unk0 = v1;
}
