typedef int s32;

extern s32 func_00441248(s32 a);
extern s32 func_00445828(s32 a);

struct func_00145BE8_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_00145BE8(void *arg0) {
    return func_00445828(func_00441248(((struct func_00145BE8_arg0 *)arg0)->unk14));
}
