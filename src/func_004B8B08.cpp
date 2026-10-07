typedef int s32;

struct S { char pad[0x860]; s32 unk860; };

extern "C" void func_004B8B08(S *arg0) {
    arg0->unk860 = 0;
}
