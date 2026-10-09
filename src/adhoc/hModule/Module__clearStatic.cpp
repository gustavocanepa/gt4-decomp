typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00304210(struct Buf00109C40 *arg0);
extern "C" void func_003063F8(s32 arg0);
extern "C" void func_003041B8(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void Module__clearStatic(void) {
    struct Buf00109C40 buf;

    func_00304210(&buf);
    func_003063F8(buf.unk0);
    func_003041B8(&buf, 2);
}
