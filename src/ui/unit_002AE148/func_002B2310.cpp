typedef int s32;

struct Obj {
    char pad[0x11C];
    s32 unk11C;
};

extern "C" s32 func_002B49D8(char *arg0);

extern "C" s32 func_002B2310(Obj *arg0) {
    s32 v0 = func_002B49D8((char *)arg0);
    return v0 + (arg0->unk11C != 0);
}
