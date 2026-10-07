typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00248C48(struct Buf00109C40 *arg0);
extern "C" void func_0024A198(s32 arg0);
extern "C" void func_00248BF0(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00249568(void) {
    struct Buf00109C40 buf;

    func_00248C48(&buf);
    func_0024A198(buf.unk0);
    func_00248BF0(&buf, 2);
}
