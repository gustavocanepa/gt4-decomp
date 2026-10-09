typedef int s32;

struct S004EF708 {
    char pad0[0x7C];
    s32 unk7C;
};

extern "C" s32 func_0056F6B8(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" s32 func_004EF898(struct S004EF708 *arg0, s32 arg1, s32 arg2) {
    return func_0056F6B8((char *)arg0 + 4, arg0->unk7C, arg1, arg2);
}
