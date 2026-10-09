typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00151888(struct Buf00109C40 *arg0);
extern "C" void func_00153B08(s32 arg0);
extern "C" void func_00151830(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void MCarModel__warp(void) {
    struct Buf00109C40 buf;

    func_00151888(&buf);
    func_00153B08(buf.unk0);
    func_00151830(&buf, 2);
}
