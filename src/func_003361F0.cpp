typedef int s32;

struct S { char pad[0x70]; s32 unk70; };

extern "C" s32 func_003361F0(S *arg0) {
    return arg0->unk70;
}
