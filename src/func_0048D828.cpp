struct Mat33 {
    float m[9];
};

extern "C" void func_0048D828(Mat33 *a, float s) {
    a->m[0] += s;
    a->m[1] += s;
    a->m[2] += s;
    a->m[3] += s;
    a->m[4] += s;
    a->m[5] += s;
    a->m[6] += s;
    a->m[7] += s;
    a->m[8] += s;
}
