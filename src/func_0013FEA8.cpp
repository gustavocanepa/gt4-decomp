typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_0013BDC0(struct Buf00109C40 *arg0);
extern "C" void func_00147D50(s32 arg0);
extern "C" void func_0013BD68(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_0013FEA8(void) {
    struct Buf00109C40 buf;

    func_0013BDC0(&buf);
    func_00147D50(buf.unk0);
    func_0013BD68(&buf, 2);
}
