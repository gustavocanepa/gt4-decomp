typedef int s32;

extern s32 func_00441248(s32 a);
extern s32 func_00445738(s32 a);

struct func_001465B8_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_001465B8(void *arg0) {
    return func_00445738(func_00441248(((struct func_001465B8_arg0 *)arg0)->unk14));
}
