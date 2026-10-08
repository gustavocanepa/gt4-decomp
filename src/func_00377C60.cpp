typedef float f32;

struct Obj {
    char pad0[0x9C0];
    f32 unk9C0;
    char pad1[0x9D4 - 0x9C0 - 4];
    f32 unk9D4;
};

extern "C" void func_00371F88(struct Obj *arg0);
extern "C" void func_0036FD88(void *arg0, f32 fparg0, f32 fparg1);

extern "C" void func_00377C60(struct Obj *arg0) {
    func_00371F88(arg0);
    func_0036FD88((char *)arg0 + 0xE28, arg0->unk9C0, arg0->unk9D4);
}
