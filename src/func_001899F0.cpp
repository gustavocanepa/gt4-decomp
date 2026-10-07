typedef int s32;

struct Inner {
    char pad0[0x10];
    s32 unk10;
};

struct Buf00109C40 {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" s32 func_0017FB28(struct Buf00109C40 *arg0);
extern "C" void func_00436640(s32 arg0);
extern "C" void func_0017FAD0(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001899F0(void) {
    struct Buf00109C40 buf;
    struct Inner *p;

    func_0017FB28(&buf);
    p = buf.ptr;
    func_00436640(p->unk10);
    func_0017FAD0(&buf, 2);
}
