typedef float f32;

struct Obj {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

extern "C" Obj *func_0041B630(Obj *arg0) {
    f32 zero;
    __asm__("mtc1 $0, %0" : "=f"(zero));
    arg0->unk0 = zero;
    arg0->unk4 = zero;
    arg0->unk8 = zero;
    return arg0;
}
