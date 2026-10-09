typedef int s32;

struct Obj {
    char pad[0xFDC];
    s32 unkFDC;
};

extern "C" s32 func_004F3A20(struct Obj *arg0, s32 arg1);

extern "C" s32 func_0060EE70(struct Obj *arg0) {
    return func_004F3A20(arg0, arg0->unkFDC);
}
