typedef int s32;

struct S { char pad[0xAC]; s32 unkAC; };

extern "C" s32 func_00206850(S *arg0) {
    return arg0->unkAC;
}
