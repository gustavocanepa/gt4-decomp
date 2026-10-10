/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Matrix {
    float m[4][4];
    Matrix()
    {
        m[0][0] = 1.0f;
        m[1][0] = 0.0f;
        m[2][0] = 0.0f;
        m[3][0] = 0.0f;
        m[0][1] = 0.0f;
        m[1][1] = 1.0f;
        m[2][1] = 0.0f;
        m[3][1] = 0.0f;
        m[0][2] = 0.0f;
        m[1][2] = 0.0f;
        m[2][2] = 1.0f;
        m[3][2] = 0.0f;
        m[0][3] = 0.0f;
        m[1][3] = 0.0f;
        m[2][3] = 0.0f;
        m[3][3] = 1.0f;
    }
};

/* The base that introduces the virtuals: g++ 2.96 puts its vptr after its own data (offset 4). */
struct Base {
    int m0;
    Base() : m0(0) {}
    virtual void f0();
};

/* Named after its vtable (0x00687070) so that _vt$10D_00687070 resolves. Without strict aliasing
   the matrix's float stores stay below the int stores, as in the original. */
struct D_00687070 : Base {
    int m8;
    Matrix mat;
    D_00687070();
    virtual void f1();
};

D_00687070::D_00687070() : m8(0)
{
}
