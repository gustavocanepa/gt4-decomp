typedef int s32;

struct Obj {
    char pad[0xC];
    void *vtbl;
};

extern char D_00688548[];
extern "C" s32 func_0044FFA0(Obj *arg0);

extern "C" s32 func_0044FF48(Obj *arg0) {
    arg0->vtbl = D_00688548;
    return func_0044FFA0(arg0);
}
