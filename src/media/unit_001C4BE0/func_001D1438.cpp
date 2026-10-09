typedef int s32;

struct S { char pad[0xC80]; s32 unkC80; };

extern "C" void func_001D1438(S *arg0) {
    arg0->unkC80 = 0;
}
