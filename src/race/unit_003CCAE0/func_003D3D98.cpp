typedef int s32;
typedef float f32;

struct Obj { char pad[0x5C]; f32 unk5C; };

extern "C" s32 func_003D3D98(Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk5C = fparg1;
    return 1;
}
