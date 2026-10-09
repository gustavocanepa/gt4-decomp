typedef int s32;

struct S { char pad[0x434]; s32 unk434; };

extern "C" s32 func_0045CC48(S *arg0) {
    return arg0->unk434;
}
