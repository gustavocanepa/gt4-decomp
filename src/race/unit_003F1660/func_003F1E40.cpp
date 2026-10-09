typedef float f32;
typedef unsigned char u8;

struct Obj {
    char pad[0x81];
    u8 unk81;
};

extern "C" f32 D_006220E0[];

extern "C" f32 func_003F1E40(Obj *arg0) {
    return D_006220E0[arg0->unk81];
}
