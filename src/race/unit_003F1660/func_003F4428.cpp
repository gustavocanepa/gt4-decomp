typedef float f32;

struct Obj {
    char pad[0xCC14];
    f32 arr[1][6];
};

extern "C" void func_003F4428(Obj *arg0, int arg1, int arg2, f32 fparg0) {
    arg0->arr[arg1][arg2] = fparg0;
}
