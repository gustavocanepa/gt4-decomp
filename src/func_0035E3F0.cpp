typedef int s32;

struct S { char pad[0x71C]; s32 unk71C; };

extern "C" s32 func_0035E3F0(S *arg0) {
    return arg0->unk71C;
}
