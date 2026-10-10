extern "C" float func_0057D1F0(float x);
extern "C" float func_0057D2B8(float x);

struct Mat {
    float m[3][3];
    void rotate(float deg)
    {
        float r = deg * 0x1.1df468p-6f;
        float c = func_0057D1F0(r);
        float s = func_0057D2B8(r);
        float a0 = m[0][0];
        float b0 = m[1][0];
        float a1 = m[0][1];
        float b1 = m[1][1];
        m[0][0] = a0 * c + b0 * s;
        m[1][0] = a0 * -s + b0 * c;
        m[0][1] = a1 * c + b1 * s;
        m[1][1] = a1 * -s + b1 * c;
    }
};

struct Obj {
    char pad[0x10];
    Mat mat;
};

extern "C" void func_0024BEF8(Obj *o, float deg)
{
    o->mat.rotate(deg);
}
