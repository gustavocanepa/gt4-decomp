struct Mat44 {
    float m[4][4];
};

struct Rot {
    float v[4];
    Rot(float a, float b, float c, float d) { v[0] = a; v[1] = b; v[2] = c; v[3] = d; }
    void toMatrix(Mat44 *out, float x, float y, float z) __asm__("func_0048A8B0");
};

struct Elem {
    char data[0x40];
    void set(Mat44 *m) __asm__("func_00489BA0");
};

struct Obj {
    int m0;
    int m4;
    int cur;
    Elem elems[1];
};

extern "C" void func_0042CCF0(Obj *o, float a, float b, float c, float d) {
    Rot r(a, b, c, d);
    Mat44 m;
    r.toMatrix(&m, 0.0f, 0.0f, 0.0f);
    o->elems[o->cur].set(&m);
}
