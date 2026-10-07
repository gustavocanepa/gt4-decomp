typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_0020B398(struct Buf00109C40 *arg0);
extern "C" void func_0020C3E0(s32 arg0);
extern "C" void func_0020B340(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_0020B780(void) {
    struct Buf00109C40 buf;

    func_0020B398(&buf);
    func_0020C3E0(buf.unk0);
    func_0020B340(&buf, 2);
}
