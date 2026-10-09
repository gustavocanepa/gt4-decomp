typedef float f32;

struct Obj {
    char pad[0x248];
    f32 unk248;
};

extern "C" void func_001C3958(struct Obj *arg0);

extern "C" void mGTShirtPS2__virtual_63(struct Obj *arg0, f32 fparg0) {
    arg0->unk248 = fparg0;
    func_001C3958(arg0);
}
