typedef int s32;

struct S { char pad[0xA30]; s32 unkA30; };

extern "C" void func_003B7B68(S *arg0, s32 arg1) {
    arg0->unkA30 = arg1;
}
