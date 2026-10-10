struct Mat44 {
    float m[16];
    void set(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11, float a12, float a13, float a14, float a15)
    {
        m[0] = a0;
        m[4] = a4;
        m[8] = a8;
        m[12] = a12;
        m[1] = a1;
        m[5] = a5;
        m[9] = a9;
        m[13] = a13;
        m[2] = a2;
        m[6] = a6;
        m[10] = a10;
        m[14] = a14;
        m[3] = a3;
        m[7] = a7;
        m[11] = a11;
        m[15] = a15;
    }
};

struct Stack {
    int pad0[2];
    int top;
    Mat44 mats[1];
};

extern "C" void func_00489BA0(Mat44 *dst, Mat44 *src);

extern "C" void func_0042CC78(Stack *s, float x, float y, float z) {
    Mat44 t;
    t.set(x, 0.0f, 0.0f, 0.0f, 0.0f, y, 0.0f, 0.0f, 0.0f, 0.0f, z, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    func_00489BA0(&s->mats[s->top], &t);
}
