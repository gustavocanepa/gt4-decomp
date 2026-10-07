typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002C28D0(struct Buf00109C40 *arg0);
extern "C" void func_002C3BA0(s32 arg0);
extern "C" void func_002C2878(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_002C33A0(void) {
    struct Buf00109C40 buf;

    func_002C28D0(&buf);
    func_002C3BA0(buf.unk0);
    func_002C2878(&buf, 2);
}
