typedef int s32;

struct S { char pad[0xCC]; s32 unkCC; };

extern "C" void func_0055D680(S *arg0, s32 arg1) {
    arg0->unkCC = arg1;
}
