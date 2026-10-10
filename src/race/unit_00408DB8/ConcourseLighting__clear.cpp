typedef int s32;
typedef float f32;

struct Elem_004099F0 {
    char data[0x50];
};

struct Obj_004099F0 {
    f32 m0;
    f32 m4;
    s32 m8;
    Elem_004099F0 mC[4];
};

extern "C" void ConcourseLighting__Unit__clear(Elem_004099F0 *e);

extern "C" void ConcourseLighting__clear(Obj_004099F0 *arg0) {
    s32 i;
    arg0->m0 = 0x1.000000p+0f;
    arg0->m4 = 0x1.000000p+0f;
    arg0->m8 = 0;
    for (i = 0; i < 4; i++) {
        ConcourseLighting__Unit__clear(&arg0->mC[i]);
    }
}
