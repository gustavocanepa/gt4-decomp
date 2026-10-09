typedef int s32;

struct S { char pad[0xAC]; s32 unkAC; };

extern "C" void func_00206858(S *arg0, s32 arg1) {
    arg0->unkAC = arg1;
}
