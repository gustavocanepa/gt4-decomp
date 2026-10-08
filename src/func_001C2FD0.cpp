typedef float f32;

struct Obj {
    char pad[0x24C];
    f32 unk24C;
};

extern "C" void func_001C3958(struct Obj *arg0);

extern "C" void func_001C2FD0(struct Obj *arg0, f32 fparg0) {
    arg0->unk24C = fparg0;
    func_001C3958(arg0);
}
