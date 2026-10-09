typedef int s32;

struct S { char pad[4]; s32 unk4; };

extern "C" s32 func_005F7310(S *arg0) {
    return arg0->unk4 != 0;
}
