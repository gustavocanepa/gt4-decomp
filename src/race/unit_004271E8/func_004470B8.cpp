typedef int s32;

struct S { char pad[0xA8]; s32 unkA8; };

extern "C" void func_004470B8(S *arg0) {
    arg0->unkA8 = 0;
}
