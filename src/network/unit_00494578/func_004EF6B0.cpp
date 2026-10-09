typedef int s32;

struct Obj {
    char pad[0x7C];
    s32 unk7C;
};

extern "C" s32 func_0056FB90(void *arg0, s32 arg1, s32 arg2);

extern "C" s32 func_004EF6B0(Obj *arg0, s32 arg1) {
    return func_0056FB90((char *)arg0 + 4, arg0->unk7C, arg1);
}
