typedef int s32;
extern "C" void func_00431D80(void *p);
struct Root { virtual ~Root(); };
struct func_0043A3F8 : Root {
    func_0043A3F8();
    virtual ~func_0043A3F8();
};
struct Elem { char p[0x1F8]; };
struct D_00687A60 : func_0043A3F8 {
    Elem a[0x7D];
    D_00687A60();
    virtual ~D_00687A60();
};
D_00687A60::D_00687A60() {
    s32 n = 0x7C;
    Elem *p = a;
    do { func_00431D80(p); p++; n--; } while (n != -1);
}
