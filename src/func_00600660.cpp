typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
};

extern char D_006872E0;

extern "C" void func_00600660(S *arg0) {
    register s32 v1 asm("$3") = (s32)&D_006872E0;
    arg0->unk0 = 0;
    arg0->unk4 = v1;
}
