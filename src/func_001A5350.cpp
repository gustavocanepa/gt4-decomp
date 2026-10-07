typedef int s32;

struct Inner {
    char pad0[0x10];
    s32 unk10;
};

struct Buf00109C40 {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" s32 func_001A4860(struct Buf00109C40 *arg0);
extern "C" void func_00430A10(s32 arg0);
extern "C" void func_001A4808(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001A5350(void) {
    struct Buf00109C40 buf;
    struct Inner *p;

    func_001A4860(&buf);
    p = buf.ptr;
    func_00430A10(p->unk10);
    func_001A4808(&buf, 2);
}
