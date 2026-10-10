struct Mat3 {
    float m[9];
};

extern "C" void func_0048D898(Mat3 *a, float s)
{
    float m0 = a->m[0] - s;
    float m1 = a->m[1] - s;
    float m2 = a->m[2] - s;
    float m3 = a->m[3] - s;
    float m4 = a->m[4] - s;
    float m5 = a->m[5] - s;
    float m6 = a->m[6] - s;
    float m7 = a->m[7] - s;
    float m8 = a->m[8] - s;
    a->m[0] = m0;
    a->m[1] = m1;
    a->m[2] = m2;
    a->m[3] = m3;
    a->m[4] = m4;
    a->m[5] = m5;
    a->m[6] = m6;
    a->m[7] = m7;
    a->m[8] = m8;
}
