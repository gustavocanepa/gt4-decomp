typedef int s32;

struct S004EF708 {
    char pad0[0x7C];
    s32 unk7C;
};

extern "C" s32 func_0056FE90(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" s32 func_004EF708(struct S004EF708 *arg0, s32 arg1, s32 arg2) {
    return func_0056FE90((char *)arg0 + 4, arg0->unk7C, arg1, arg2);
}
