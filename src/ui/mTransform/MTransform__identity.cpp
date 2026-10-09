typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_0024B2A0(struct Buf00109C40 *arg0);
extern "C" void func_0024C060(s32 arg0);
extern "C" void func_0024B248(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void MTransform__identity(void) {
    struct Buf00109C40 buf;

    func_0024B2A0(&buf);
    func_0024C060(buf.unk0);
    func_0024B248(&buf, 2);
}
