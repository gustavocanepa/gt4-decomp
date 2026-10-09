typedef float f32;
typedef int s32;

struct Obj { char pad[0x68]; f32 unk68; };

extern "C" s32 func_003D3DA8(Obj *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f0;

    temp_f0 = arg0->unk68 + fparg0;
    arg0->unk68 = temp_f0;
    if (fparg1 <= temp_f0) {
        arg0->unk68 = fparg1;
        return 1;
    }
    return 0;
}
