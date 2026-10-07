typedef int s32;

struct Inner {
    char pad0[0x10];
    s32 unk10;
};

struct Buf00109C40 {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" s32 func_0017D2C0(struct Buf00109C40 *arg0);
extern "C" void func_001D1438(s32 arg0);
extern "C" void func_0017D268(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_0017DC40(void) {
    struct Buf00109C40 buf;
    struct Inner *p;

    func_0017D2C0(&buf);
    p = buf.ptr;
    func_001D1438(p->unk10);
    func_0017D268(&buf, 2);
}
