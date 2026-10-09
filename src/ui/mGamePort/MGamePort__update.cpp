typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_0029CA40(struct Buf00109C40 *arg0);
extern "C" void func_0029C658(s32 arg0);
extern "C" void func_0029C9E8(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void MGamePort__update(void) {
    struct Buf00109C40 buf;

    func_0029CA40(&buf);
    func_0029C658(buf.unk0);
    func_0029C9E8(&buf, 2);
}
