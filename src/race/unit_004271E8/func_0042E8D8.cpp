typedef long long s64;
struct func_0043A3F8 {
    func_0043A3F8();
    virtual ~func_0043A3F8();
};
struct D_006878C8 : func_0043A3F8 {
    int m4;
    s64 a[1024];
    s64 b[128];
    int m2408;
    D_006878C8();
    virtual ~D_006878C8();
};

D_006878C8::D_006878C8() {
    m2408 = 0;
    for (int i = 0; i < 1024; i++) a[i] = -1;
    for (int i = 0; i < 128; i++) b[i] = -1;
}
