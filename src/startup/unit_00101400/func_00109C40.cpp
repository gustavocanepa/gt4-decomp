typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001DC8F0(struct Buf00109C40 *arg0);
extern "C" void func_001FBA68(s32 arg0);
extern "C" void func_001DC5F8(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00109C40(void) {
    struct Buf00109C40 buf;

    func_001DC8F0(&buf);
    func_001FBA68(buf.unk0);
    func_001DC5F8(&buf, 2);
}
