typedef float f32;

struct Obj {
    char pad0[0xC];
    f32 unkC;
};

extern "C" void func_00350678(Obj *arg0);

extern "C" f32 func_003507A8(Obj *arg0) {
    func_00350678(arg0);
    return arg0->unkC;
}
