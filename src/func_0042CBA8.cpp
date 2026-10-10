struct Mat44 {
    float m[4][4];
};

struct Rot {
    float v[4];
    Rot() __asm__("func_0048AF20");
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

extern "C" void func_0042CBA8(Obj *o) {
    Rot r;
    Mat44 m;
    r.toMatrix(&m, 0.0f, 0.0f, 0.0f);
    o->elems[o->cur].set(&m);
}
