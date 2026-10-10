typedef int s32;
typedef float f32;

struct Obj_004694A0 {
    char pad0[0x44];
    s32 m44;
    char m48[8];
    char pad50[3];
    signed char m53;
    char pad54[4];
    f32 m58;
    f32 m5C;
    f32 m60;
    f32 m64;
};

extern "C" void func_004694A0(Obj_004694A0 *arg0) {
    s32 i;
    arg0->m44 = 0;
    for (i = 7; i >= 0; i--) {
        arg0->m48[i] = 0;
    }
    arg0->m53 = -1;
    arg0->m58 = 0x1.f40000p+9f;
    arg0->m5C = 0x1.f40000p+9f;
    arg0->m60 = 0x1.f40000p+9f;
    arg0->m64 = -0x1.f40000p+9f;
}
