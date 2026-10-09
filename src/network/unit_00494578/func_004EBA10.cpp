typedef int s32;

struct S { char pad[0x48]; s32 unk48; };

extern "C" s32 func_004EBA10(S *arg0) {
    return arg0->unk48;
}
