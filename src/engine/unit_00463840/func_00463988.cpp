typedef float f32;
typedef unsigned short u16;

struct Obj {
    char pad[0x68];
    u16 unk68;
};

extern "C" f32 func_00463988(Obj *arg0, f32 fparg0, f32 fparg1) {
    return fparg0 + ((fparg1 - fparg0) * ((f32)arg0->unk68 * 0.000030517578125f));
}
