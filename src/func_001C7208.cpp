typedef int s32;

struct Obj001C7208 {
    char pad[0xB0];
    void *unkB0;
};

extern char D_00660D80[];
extern "C" s32 func_001C7260(Obj001C7208 *arg0);

extern "C" s32 func_001C7208(Obj001C7208 *arg0) {
    arg0->unkB0 = D_00660D80;
    return func_001C7260(arg0);
}
