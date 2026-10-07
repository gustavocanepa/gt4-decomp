typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_0021D9D0(struct Buf00109C40 *arg0);
extern "C" void func_0021FE08(s32 arg0);
extern "C" void func_0021D978(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_0021E4A0(void) {
    struct Buf00109C40 buf;

    func_0021D9D0(&buf);
    func_0021FE08(buf.unk0);
    func_0021D978(&buf, 2);
}
