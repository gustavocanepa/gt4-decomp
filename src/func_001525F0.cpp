typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00151888(struct Buf00109C40 *arg0);
extern "C" void func_00153E20(s32 arg0);
extern "C" void func_00151830(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001525F0(void) {
    struct Buf00109C40 buf;

    func_00151888(&buf);
    func_00153E20(buf.unk0);
    func_00151830(&buf, 2);
}
