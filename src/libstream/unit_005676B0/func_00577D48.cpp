struct StreamBase {
    int unk0;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int flush();
};

struct Stream : StreamBase {
    int unk8;
    int binary;
};

extern "C" void func_005779E8(Stream *s);
extern "C" void func_00580CD8(int a);
extern "C" void func_005813F8(int mode);
extern "C" void func_00577A08(Stream *s);

extern "C" void func_00577D48(Stream *s) {
    int mode = s->binary ? 2 : 1;
    func_005779E8(s);
    func_00580CD8(0);
    func_005813F8(mode);
    s->flush();
    func_005779E8(s);
    func_00580CD8(0);
    func_005813F8(mode);
    func_00577A08(s);
}
