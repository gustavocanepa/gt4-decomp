typedef int s32;

struct Inner {
    char pad0[0x20];
    s32 unk20;
};

struct Buf00109C40 {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" s32 func_001792D8(struct Buf00109C40 *arg0);
extern "C" void func_001D28A0(s32 arg0);
extern "C" void func_001D2938(void);
extern "C" void func_00179280(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001799C0(void) {
    struct Buf00109C40 buf;
    struct Inner *p;

    func_001792D8(&buf);
    p = buf.ptr;
    func_001D28A0(p->unk20);
    func_001D2938();
    func_00179280(&buf, 2);
}
