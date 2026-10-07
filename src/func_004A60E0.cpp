typedef float f32;

struct Vec4 {
    char pad[0xAF0];
    f32 unkAF0;
    f32 unkAF4;
    f32 unkAF8;
    f32 unkAFC;
};

extern "C" void func_004A60E0(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    Vec4 *p = (Vec4 *)0x70002000;
    p->unkAF0 = fparg0;
    p->unkAF4 = fparg1;
    p->unkAF8 = fparg2;
    p->unkAFC = fparg3;
}
