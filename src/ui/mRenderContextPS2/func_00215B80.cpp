typedef int s32;

struct S { char pad[0x10]; s32 unk10; };

extern "C" s32 func_00215B80(S *arg0) {
    return arg0->unk10;
}
