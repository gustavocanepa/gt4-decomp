typedef int s32;
extern "C" {
s32 func_00578CF0(s32 a, s32 b);
void func_00578148(void *p, s32 a);
void func_00578500(s32 a);
void func_00578168(void *p, s32 a, s32 b, s32 c, s32 d);
}
struct func_00578048 {
    s32 m0;
    char pad[0x28];
    s32 m2C;
    s32 m30;
    char pad2[4];
    func_00578048();
    virtual ~func_00578048();
};
struct D_00689938 : func_00578048 {
    s32 m3C;
    D_00689938();
    virtual ~D_00689938();
};
D_00689938::D_00689938() {
    s32 v = func_00578CF0(0x40, 0x40);
    m3C = v;
    m2C = v;
    m30 = 0x40;
    func_00578148(this, 0x50555354);
    func_00578500(m0);
    func_00578168(this, 0, 0, m3C, 0x40);
}
