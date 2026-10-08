typedef float f32;
typedef unsigned char u8;

struct Obj {
    u8 pad[0x88];
    f32 unk88;
};

extern "C" void func_00267DB8(Obj *arg0, f32 fparg0) {
    f32 v = fparg0;
    if (v < 0.0f) {
        v = 0.0f;
    }
    if (1.0f < v) {
        v = 1.0f;
    }
    arg0->unk88 = v;
}
