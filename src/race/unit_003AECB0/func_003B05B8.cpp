/* compiler: ee-gcc2.96-no-strict-aliasing */
struct func_003B05B8 {
    int m0;
    float m4;
    int m8;
    float mC;
    float m10;
    float v[16];
    int m54;
    float m58;
    float m5C;
    func_003B05B8 &operator=(const func_003B05B8 &o);
};

func_003B05B8 &func_003B05B8::operator=(const func_003B05B8 &o)
{
    m0 = o.m0;
    m4 = o.m4;
    m8 = o.m8;
    mC = o.mC;
    m10 = o.m10;
    for (int i = 0; i < 16; i++)
        v[i] = o.v[i];
    m54 = o.m54;
    m58 = o.m58;
    m5C = o.m5C;
    return *this;
}
