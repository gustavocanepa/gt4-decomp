typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x778];
    f32 arr778[4];
};

extern "C" void func_0035A618(struct Obj *arg0, s32 arg1, f32 fparg0) {
    if (arg1 < 4) {
        arg0->arr778[arg1] = fparg0;
    }
}
