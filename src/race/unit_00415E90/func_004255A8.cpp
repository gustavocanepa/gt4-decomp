/* A 4x4 matrix stored by columns; set() takes the elements row by row (an inline call keeps the
   constant arguments in registers: the zeros are stored from one FPU register). */
struct Mat {
    float m[4][4];
    void set(float m00, float m01, float m02, float m03,
             float m10, float m11, float m12, float m13,
             float m20, float m21, float m22, float m23,
             float m30, float m31, float m32, float m33) {
        m[0][0] = m00;
        m[1][0] = m01;
        m[2][0] = m02;
        m[3][0] = m03;
        m[0][1] = m10;
        m[1][1] = m11;
        m[2][1] = m12;
        m[3][1] = m13;
        m[0][2] = m20;
        m[1][2] = m21;
        m[2][2] = m22;
        m[3][2] = m23;
        m[0][3] = m30;
        m[1][3] = m31;
        m[2][3] = m32;
        m[3][3] = m33;
    }
};

/* Scale matrix. */
extern "C" void func_004255A8(Mat *p, float x, float y, float z) {
    p->set(x, 0.0f, 0.0f, 0.0f,
           0.0f, y, 0.0f, 0.0f,
           0.0f, 0.0f, z, 0.0f,
           0.0f, 0.0f, 0.0f, 1.0f);
}
