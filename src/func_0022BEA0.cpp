typedef int s32;

struct Inner {
    char pad0[0x10];
    s32 unk10;
};

struct Buf00109C40 {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" s32 func_0022AD20(struct Buf00109C40 *arg0);
extern "C" void func_00251C08(s32 arg0);
extern "C" void func_0022ACC8(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_0022BEA0(void) {
    struct Buf00109C40 buf;
    struct Inner *p;

    func_0022AD20(&buf);
    p = buf.ptr;
    func_00251C08(p->unk10);
    func_0022ACC8(&buf, 2);
}
