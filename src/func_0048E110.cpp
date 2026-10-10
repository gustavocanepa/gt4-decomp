struct Mat44 {
    float m[16];
};

extern "C" void func_0048E110(Mat44 *o, float a0, float a1, float a2, float a3, float a4, float a5,
                              float a6, float a7, float a8, float a9, float a10, float a11,
                              float a12, float a13, float a14, float a15) {
    o->m[0] = a0;
    o->m[1] = a1;
    o->m[2] = a2;
    o->m[3] = a3;
    o->m[4] = a4;
    o->m[5] = a5;
    o->m[6] = a6;
    o->m[7] = a7;
    o->m[8] = a8;
    o->m[9] = a9;
    o->m[10] = a10;
    o->m[11] = a11;
    o->m[12] = a12;
    o->m[13] = a13;
    o->m[14] = a14;
    o->m[15] = a15;
}
