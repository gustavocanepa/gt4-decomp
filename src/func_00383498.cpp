typedef int s32;

struct S { char pad[0x180]; s32 unk180; };

extern "C" void func_00383498(S *arg0, s32 arg1) {
    arg0->unk180 = arg1;
}
