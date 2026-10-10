typedef int s32;
extern "C" void func_00430958(s32 *p);
struct Root { virtual ~Root(); };
struct func_0043A3F8 : Root {
    func_0043A3F8();
    virtual ~func_0043A3F8();
};
struct D_00687A20 : func_0043A3F8 {
    s32 a[0x300];
    D_00687A20();
    virtual ~D_00687A20();
};
D_00687A20::D_00687A20() {
    s32 n = 0x2FF;
    s32 *p = a;
    do { func_00430958(p); p++; n--; } while (n != -1);
}
