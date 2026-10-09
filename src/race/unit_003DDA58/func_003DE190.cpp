typedef int s32;

struct S { char pad[0x2C]; s32 unk2C; };

extern "C" s32 func_003DE190(S *arg0) {
    return arg0->unk2C;
}
