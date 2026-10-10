typedef int s32;

extern s32 func_00441248(s32 a);
extern s32 func_00445350(s32 a);

struct func_00146598_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_00146598(void *arg0) {
    return func_00445350(func_00441248(((struct func_00146598_arg0 *)arg0)->unk14));
}
